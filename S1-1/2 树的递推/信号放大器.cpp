#include<iostream>
#include<vector>
using namespace std;

const int N = 2e4 + 5;
struct Edge {int v,w;};
vector<Edge> G[N];
int s[N],n,m,maxw = 0,ans = 0;

void dfs(int u,int pa) {
	for (auto [v,w] : G[u]) {
		if (v == pa) continue;
		dfs(v,u);
		if (s[v] + w >= m) ans++,s[u] = max(s[u],w);
		else s[u] = max(s[u],s[v] + w);
	}
}

int main() {
	cin >> n;
	for (int i = 1;i <= n;i++) {
		int k;
		cin >> k;
		for (int j = 1;j <= k;j++) {
			int u,w;
			cin >> u >> w;
			G[i].push_back({u,w});
			maxw = max(maxw,w);
		}
	}
	cin >> m;
	if (maxw >= m) {
		cout << "No solution." << endl;
		return 0;
	}
	dfs(1,0);
	cout << ans << endl;
	return 0;
}