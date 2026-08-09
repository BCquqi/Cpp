#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;

const int N = 105;
int p[N],dp[N][N][N];

signed main() {
	freopen("agent.in","r",stdin);
	freopen("agent.out","w",stdout);
	int n,x,ans = 1e18;
	cin >> n >> x;
	for (int i = 1;i <= n;i++) cin >> p[i];
	for (int c = 1;c <= n;c++) {
		memset(dp,-0x3f,sizeof dp);
		dp[0][0][0] = 0;
		for (int i = 1;i <= n;i++)
			for (int j = 0;j <= i;j++)
				for (int k = 0;k <= c - 1;k++) {
					dp[i][j][k] = dp[i - 1][j][k];
					if (j) dp[i][j][k] = max(dp[i][j][k],dp[i - 1][j - 1][((k - p[i]) % c + c) % c] + p[i]);
				}
		if (dp[n][c][x % c] >= 0 && dp[n][c][x % c] <= x)
			ans = min(ans,(x - dp[n][c][x % c]) / c);
	}
	cout << ans << endl;
	return 0;
}
