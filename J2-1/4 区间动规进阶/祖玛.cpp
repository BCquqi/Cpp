#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 505;
int dp[N][N],c[N];

int main(){
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> c[i];
	memset(dp,0x3f,sizeof dp);
	for (int i = 1;i <= n;i++)
	{
		dp[i][i] = 1;
		if (c[i] == c[i - 1]) dp[i - 1][i] = 1;
		else dp[i - 1][i] = 2;
	}
	for (int len = 3;len <= n;len++)
	{
		for (int i = 1;i + len - 1 <= n;i++)
		{
			int j = i + len - 1;
			if (c[i] == c[j]) dp[i][j] = dp[i + 1][j - 1];
			for (int k = i;k < j;k++) dp[i][j] = min(dp[i][j],dp[i][k] + dp[k + 1][j]);
		}
	}
	cout << dp[1][n] << endl;
	return 0;
}