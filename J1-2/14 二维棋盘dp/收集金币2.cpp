#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int a[105][105],dp[105][105][1005];

int main(){
	int n,p;
	cin >> n >> p;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			cin >> a[i][j];
	memset(dp,-0x3f,sizeof dp);
	dp[0][1][0] = 0,dp[1][0][0] = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			for (int k = 0;k < p;k++)
			{
				dp[i][j][k] = max(dp[i - 1][j][k],dp[i][j - 1][k]);
				int x = (k - a[i][j] % p + p) % p;
				dp[i][j][k] = max(dp[i][j][k],dp[i - 1][j][x] + a[i][j]);
				dp[i][j][k] = max(dp[i][j][k],dp[i][j - 1][x] + a[i][j]);
			}
	cout << dp[n][n][0] << endl;
	return 0;
}
