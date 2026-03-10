#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

const int N = 2e5 + 5;
int n,x[N],y[N],dis[N]; bool vis[N];
struct Node {int v,w;};
struct Point {int x,y,id;} a[N];
vector<Node> G[N];
bool operator < (const Node &x,const Node &y) {return x.w > y.w;}
bool cmpx(Point x,Point y) {return x.x < y.x;}
bool cmpy(Point x,Point y) {return x.y < y.y;}

void dijkstra() {
	memset(dis,0x3f,sizeof dis);
	priority_queue<Node> q;
	dis[1] = 0;
	q.push({1,dis[1]});
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
	cin >> n;
	for (int i = 1;i <= n;i++) {cin >> a[i].x >> a[i].y; a[i].id = i;}
	sort(a + 1,a + n + 1,cmpx);
	for (int i = 2;i <= n;i++) {
		int u = a[i - 1].id,v = a[i].id;
		int w = min(abs(a[i].x - a[i - 1].x),abs(a[i].y - a[i - 1].y));
		G[u].push_back({v,w}); G[v].push_back({u,w});
	}
	sort(a + 1,a + n + 1,cmpy);
	for (int i = 2;i <= n;i++) {
		int u = a[i - 1].id,v = a[i].id;
		int w = min(abs(a[i].x - a[i - 1].x),abs(a[i].y - a[i - 1].y));
		G[u].push_back({v,w}); G[v].push_back({u,w});
	}
	dijkstra();
	cout << dis[n] << endl;
	return 0;
}