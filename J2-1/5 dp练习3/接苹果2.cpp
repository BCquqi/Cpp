#include<iostream>
#include <cstring>
using namespace std;

const int N = 2005;
int a[N],dp[N][105][55];

int main()
{
	int t,w,c;
	cin >> t >> w >> c;
	for (int i = 1;i <= t;i++) cin >> a[i];
	memset(dp,-0x3f,sizeof dp);
	dp[0][0][1] = 0;
	for (int i = 1;i <= t;i++)
		for (int j = 0;j <= w;j++)
			for (int k = 1;k <= c;k++)
			{
				dp[i][j][k] = max(dp[i][j][k],dp[i - 1][j][k]);
				if (a[i] == k) dp[i][j][a[i]] = max(dp[i][j][a[i]], dp[i - 1][j][k] + 1);
				else if (j >= 1) dp[i][j][a[i]] = max(dp[i][j][a[i]],dp[i - 1][j - 1][k] + 1);
			}
	int ans = 0;
	for (int i = 1;i <= c;i++)
		for (int j = 0; j <= w; j++)
			ans = max(ans,dp[t][j][i]);
	cout << ans << endl;
	return 0;
}