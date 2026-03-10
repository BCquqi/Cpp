#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

const int N = 1e5 + 5;
int n,m,s,dis[N]; bool vis[N];
struct Node {int v,w;};
vector<Node> G[N];

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

int main() {
	cin >> n >> m >> s;
	for (int i = 1;i <= m;i++) {
		int u,v,w;
		cin >> u >> v >> w;
		G[u].push_back({v,w});
	}
	dijkstra();
	for (int i = 1;i <= n;i++)
		if (i == s) cout << 0 << ' ';
		else if (dis[i] == 0x3f3f3f3f) cout << 2147483647 << ' ';
		else cout << dis[i] << ' ';
	cout << endl;
	return 0;
}