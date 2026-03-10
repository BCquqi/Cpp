#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

int a[1005][1005],dp[1005][1005];

int main()
{
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			cin >> a[i][j];
	memset(dp,0x3f,sizeof dp);
	a[1][1] = 0,dp[0][1] = 0,dp[1][0] = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			dp[i][j] = min(dp[i - 1][j],dp[i][j - 1]) + a[i][j];
	cout << dp[n][m] << endl;
	return 0;
}
