#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 10005;
vector<int> G[N];
int len[N],in[N],topo[N],dp[N],n,cur = 0;
queue<int> q;

void topo_sort() {
	for (int i = 1;i <= n;i++)
		if (in[i] == 0) {
			q.push(i);
			dp[i] = len[i];
		}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		topo[++cur] = u;
		for (auto v : G[u]) {
			if (--in[v] == 0) q.push(v);
			dp[v] = max(dp[v],dp[u] + len[v]);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1;i <= n;i++) {
		int u,v;
		cin >> v >> len[i];
		while (cin >> u) {
			if (u == 0) break;
			G[u].push_back(v);
			in[v]++;
		}
	}
	topo_sort();
	int ans = 0;
	for (int i = 1;i <= n;i++) ans = max(ans,dp[i]);
	cout << ans << endl;
	return 0;
}