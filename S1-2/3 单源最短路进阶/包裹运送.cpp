#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 4e4 + 5;
int dis1[N],dis2[N],dis3[N],vis[N];
struct Node {int v,w;};
vector<int> G[N];
bool operator < (const Node &x,const Node &y) {return x.w > y.w;}

void dijkstra(int dis[N],int s) {
	for (int i = 1;i <= 40000;i++) dis[i] = 1e9,vis[i] = 0;
	priority_queue<Node> pq;
	dis[s] = 0;
	pq.push({s,0});
	while (!pq.empty()) {
		int u = pq.top().v; pq.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto v : G[u]) {
			if (vis[v]) continue;
			if (dis[v] <= dis[u] + 1) continue;
			dis[v] = dis[u] + 1;
			pq.push({v,dis[v]});
		}
	}
}

int main() {
	int b,e,p,n,m,ans = 1e9;
	cin >> b >> e >> p >> n >> m;
	for (int i = 1;i <= m;i++) {
		int u,v;
		cin >> u >> v;
		G[u].push_back(v); G[v].push_back(u);
	}
	dijkstra(dis1,1); dijkstra(dis2,2); dijkstra(dis3,n);
	for (int i = 1;i <= n;i++) ans = min(ans,b * dis1[i] + e * dis2[i] + p * dis3[i]);
	cout << ans << endl;
	return 0;
}