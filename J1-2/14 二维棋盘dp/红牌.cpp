#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int a[2005][2005],dp[2005][2005];

int main() {
	int n,m;
	cin >> m >> n;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			cin >> a[i][j];
	memset(dp,0x3f,sizeof dp);
	for (int i = 1;i <= n;i++) dp[i][0] = 0;
	for (int j = 1;j <= m;j++)
	{
		dp[1][j] = min(dp[1][j - 1],dp[n][j - 1]) + a[1][j];
		for (int i = 2;i <= n;i++) dp[i][j] = min(dp[i][j - 1],dp[i - 1][j - 1]) + a[i][j];
	}
	int ans = 1e9;
	for (int i = 1;i <= n;i++) ans = min(ans,dp[i][m]);
	cout << ans << endl;
	return 0;
}
