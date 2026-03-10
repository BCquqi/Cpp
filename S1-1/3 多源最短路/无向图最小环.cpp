#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 105;
long long dp[N][N],G[N][N];

void solve() {
	int n,m;
	long long ans = 1e9;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			dp[i][j] = 1e9;
	while (m--) {
		int a,b,c;
		cin >> a >> b >> c;
		dp[a][b] = dp[b][a] = c;
	}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			G[i][j] = dp[i][j];
	for (int i = 1;i <= n;i++) dp[i][i] = 0;
	for (int k = 1;k <= n;k++) {
		for (int i = 1;i < k;i++)
			for (int j = i + 1;j <= k;j++)
				ans = min(ans,dp[i][j] + G[i][k] + G[k][j]);
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);
	}
	if (ans == 1e9) cout << "No Simple Cycle" << endl;
	else cout << ans << endl;
	return ;
}

int main() {
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}