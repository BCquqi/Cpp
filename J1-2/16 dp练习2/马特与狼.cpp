#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

int a[305],b[305],dp[305][305];

int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++) cin >> b[i];
	memset(dp,0x3f,sizeof dp);
	for (int i = 0;i <= n + 1;i++) dp[i][i] = 0,dp[i][i + 1] = 0;
	for (int len = 3;len <= n + 2;len++)
		for (int i = 0;i + len - 1 <= n + 1;i++)
		{
			int j = i + len - 1;
			for (int k = i + 1;k < j;k++)
				dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j] + a[k] + b[i] + b[j]);
		}
	cout << dp[0][n + 1] << endl;
	return 0;
}
