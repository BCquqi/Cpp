#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

const int N = 1e5 + 5;
int n,e,dis[N],cnt[N]; bool vis[N];
struct Node {int v,w;};
vector<Node> G[N];

bool operator < (const Node &x,const Node &y) {return x.w > y.w;}

void dijkstra() {
	memset(dis,0x3f,sizeof dis);
	priority_queue<Node> q;
	dis[1] = 0,cnt[1] = 1;
	q.push({1,dis[1]});
	while (!q.empty()) {
		int u = q.top().v; q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto p : G[u]) {
			int v = p.v,w = p.w;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				cnt[v] = cnt[u];
				q.push({v,dis[v]});
			} else if (dis[v] == dis[u] + w) cnt[v] += cnt[u];
		}
	}
}

int main() {
	cin >> n >> e;
	for (int i = 1;i <= e;i++) {
		int u,v,c;
		cin >> u >> v >> c;
		G[u].push_back({v,c});
	}
	dijkstra();
	if (dis[n] == 0x3f3f3f3f) cout << "No answer" << endl;
	else cout << dis[n] << ' ' << cnt[n] << endl;
	return 0;
}