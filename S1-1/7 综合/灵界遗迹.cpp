#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

const int N = 305;
int dp[N][N],a[N];
long long sum[N][N];

int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	memset(dp,0x3f,sizeof dp);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++) {
			char c;
			cin >> c;
			if (c == 'Y') dp[i][j] = 1,sum[i][j] = a[i] + a[j];
		}
	for (int i = 1;i <= n;i++) dp[i][i] = 0,sum[i][i] = a[i];
	for (int k = 1;k <= n;k++)
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++) {
				if (dp[i][j] > dp[i][k] + dp[k][j]) {
					dp[i][j] = dp[i][k] + dp[k][j];
					sum[i][j] = sum[i][k] + sum[k][j] - a[k];
				} else if (dp[i][j] == dp[i][k] + dp[k][j])
					sum[i][j] = max(sum[i][j],sum[i][k] + sum[k][j] - a[k]);
			}
	int q;
	cin >> q;
	while (q--) {
		int u,v;
		cin >> u >> v;
		if (dp[u][v] == 0x3f3f3f3f) cout << "Impossible" << endl;
		else cout << dp[u][v] << ' ' << sum[u][v] << endl;
	}
	return 0;
}