#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int N = 2e5 + 5;
int a[N],dp[N],in[N],n,m,ans = 0;
queue<int> q;
vector<int> G[N];

void topo_sort() {
	for (int i = 1;i <= n;i++) {
		if (in[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto v : G[u]) {
			if (--in[v] == 0) q.push(v);
			dp[v] = max(dp[v],dp[u] + 1);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= m;i++) {
		int u,v;
		cin >> u >> v;
		if (a[u] < a[v]) {
			G[u].push_back(v);
			in[v]++;
		}
		else {
			G[v].push_back(u);
			in[u]++;
		}
	}
    memset(dp,-0x3f,sizeof dp);
	dp[1] = 1;
	topo_sort();
	for (int i = 1;i <= n;i++) ans = max(ans,dp[i]);
	cout << ans << endl;
	return 0;
}