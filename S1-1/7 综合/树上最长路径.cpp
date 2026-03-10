#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

const int N = 2e5 + 5;
struct Edge {int v,w;};
vector<Edge> G[N];
long long dis[N];

void dfs(int u,int pa) {
	for (auto p : G[u]) {
		int v = p.v,w = p.w;
		if (v == pa) continue;
		dis[v] = dis[u] + w;
		dfs(v,u);
	}
}

int main() {
	long long n,id = 0,ans = 0;
	cin >> n;
	for (int i = 1;i < n;i++) {
		int u,v,w;
		cin >> u >> v >> w;
		G[u].push_back({v,w}); G[v].push_back({u,w});
	}
	dfs(1,0);
	for (int i = 1;i <= n;i++)
		if (dis[i] > dis[id]) id = i;
	memset(dis,0,sizeof dis);
	dfs(id,0);
	for (int i = 1;i <= n;i++) ans = max(ans,dis[i]);
	cout << ans << endl;
	return 0;
}