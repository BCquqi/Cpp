#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int dp[2][100005];

int main() 
{
	memset(dp,0x3f,sizeof dp);
	int n,t;
	cin >> n;
	dp[0][0] = 0;
	for (int i = 1;i * i * i * i <= n;i++)
	{
		t = i * i * i * i;
		for (int j = 0;j <= n;j++)
		{
			dp[i & 1][j] = dp[i - 1 & 1][j];
			if (j >= i * i * i * i) dp[i & 1][j] = min(dp[i & 1][j],dp[i & 1][j - i * i * i * i] + 1);
		}
	}
	cout << dp[t & 1][n] << endl;
	return 0;
}
