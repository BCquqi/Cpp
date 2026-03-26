#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

const int N = 1e5 + 5;
struct Node {int x,y,id;} p[2 * N];
struct Edge {int v,w;};
vector<Edge> G[2 * N];
int dis[2 * N],n,m;
bool vis[2 * N];

bool operator < (const Edge &x,const Edge &y) {return x.w > y.w;}

void dijkstra(int s) {
	memset(dis,0x3f,sizeof dis);
	priority_queue<Edge> q;
	dis[s] = dis[s + m] = 0;
	q.push({s,0}); q.push({s + m,0});
	while (!q.empty()) {
		int u = q.top().v; q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto [v,w] : G[u]) {
			if (vis[v]) continue;
			if (dis[v] <= dis[u] + w) continue;
			dis[v] = dis[u] + w;
			q.push({v,dis[v]});
		}
	}
}

int main() {
	cin >> n >> m;
	m += 2;
	for (int i = 1;i <= m;i++) {
		cin >> p[i].x >> p[i].y;
		p[i].id = i;
	}
	sort(p + 1,p + m + 1,[](Node x,Node y){return (x.x != y.x ? x.x < y.x : x.y < y.y);});
	for (int i = 2;i <= m;i++)
		if (p[i].x == p[i - 1].x) {
			int u = p[i].id,v = p[i - 1].id;
			int w = 2 * abs(p[i].y - p[i - 1].y);
			G[u].push_back({v,w}); G[v].push_back({u,w});
		}
	sort(p + 1,p + m + 1,[](Node x,Node y){return (x.y != y.y ? x.y < y.y : x.x < y.x);});
	for (int i = 2;i <= m;i++)
		if (p[i].y == p[i - 1].y) {
			int u = p[i].id + m,v = p[i - 1].id + m;
			int w = 2 * abs(p[i].x - p[i - 1].x);
			G[u].push_back({v,w}); G[v].push_back({u,w});
		}
	for (int i = 1;i <= m;i++) {G[i].push_back({i + m,1}); G[i + m].push_back({i,1});}
	dijkstra(m - 1);
	int ans = min(dis[m],dis[2 * m]);
	cout << (ans > 1e9 ? -1 : ans) << endl;
	return 0;
}