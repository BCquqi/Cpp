#include<iostream>
#include<vector>
using namespace std;

const int N = 5e5 + 5;
struct Edge {int v,w;};
vector<Edge> G[N];
long long dp[N],ans = 0;

void dfs(int u,int pa) {
	for (auto p : G[u]) {
		int v = p.v,w = p.w;
		if (v == pa) continue;
		dfs(v,u);
		dp[u] = max(dp[u],dp[v] + w);
	}
	for (auto p : G[u]) {
		int v = p.v,w = p.w;
		if (v == pa) continue;
		ans += dp[u] - dp[v] - w;
	}
}

int main() {
	int n,s;
	cin >> n >> s;
	for (int i = 1;i < n;i++) {
		int a,b,t;
		cin >> a >> b >> t;
		G[a].push_back({b,t}); G[b].push_back({a,t});
	}
	dfs(s,0);
	cout << ans << endl;
	return 0;
}