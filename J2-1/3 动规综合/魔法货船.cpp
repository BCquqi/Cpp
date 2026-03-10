#include<iostream>
using namespace std;

const int N = 105;
int w[N],v[N],s[N],c[N],dp[2][10005];

int main()
{
	int n,m,maxs = 0;
	cin >> n >> m >> s[0];
	maxs = s[0];
	for (int i = 1;i <= n;i++) cin >> w[i];
	for (int i = 1;i <= n;i++) cin >> v[i];
	for (int i = 1;i <= m;i++) {cin >> s[i]; maxs = max(maxs,s[i]);}
	for (int i = 1;i <= m;i++) cin >> c[i];
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= maxs;j++)
		{
			dp[i & 1][j] = dp[i - 1 & 1][j];
			if (j >= w[i]) dp[i & 1][j] = max(dp[i & 1][j],dp[i - 1 & 1][j - w[i]] + v[i]);
		}
	int ans = -1e9;
	for (int i = 0;i <= m;i++)
		ans = max(ans,dp[n & 1][s[i]] - c[i]);
	cout << ans << endl;
	return 0;
}
