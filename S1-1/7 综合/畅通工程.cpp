#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

const int N = 2005;
struct Node {int v; long long w;};
vector<Node> G[N];
long long dis[N];
int n,m,s,t;
bool vis[N];
bool operator < (const Node &x,const Node &y) {return x.w > y.w;}

void dijkstra() {
	memset(dis,0x3f,sizeof dis);
	priority_queue<Node> q;
	dis[s] = 0;
	q.push({s,dis[s]});
	while (!q.empty()) {
		int u = q.top().v; q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto p : G[u]) {
			int v = p.v,w = p.w;
			if (vis[v]) continue;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push({v,dis[v]});
			}
		}
	}
}

void solve() {
	for (int i = 1;i <= N;i++) G[i].clear();
	memset(vis,0,sizeof vis);
	cin >> n >> m;
	for (int i = 1;i <= m;i++) {
		int u,v,w;
		cin >> u >> v >> w;
		u++,v++;
		G[u].push_back({v,w}); G[v].push_back({u,w});
	}
	cin >> s >> t;
	s++,t++;
	dijkstra();
	cout << (dis[t] == 0x3f3f3f3f3f3f3f3f ? -1 : dis[t]) << endl;
	return ;
}

int main() {
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}