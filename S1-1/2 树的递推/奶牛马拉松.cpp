#include<iostream>
#include<vector>
using namespace std;

const int N = 4e4 + 5;
struct Node {int v,w;};
vector<Node> G[N];
int dis[N],id,ans = 0;

void dfs(int u,int pa) {
	if (pa == 0) dis[u] = 0;
	for (auto [v,w] : G[u]) {
		if (v == pa) continue;
		dis[v] = dis[u] + w;
		dfs(v,u);
	}
}

int main() {
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= m;i++) {
		int x,y,d; char p;
		cin >> x >> y >> d >> p;
		G[x].push_back({y,d}); G[y].push_back({x,d});
	}
	dfs(1,0);
	for (int i = 1;i <= n;i++)
		if (dis[i] > dis[id]) id = i;
	dfs(id,0);
	for (int i = 1;i <= n;i++) ans = max(ans,dis[i]);
	cout << ans << endl;
	return 0;
}