#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

const int N = 1e5 + 5;
struct Edge {int v,w;};
vector<Edge> G[N];
int dis[N],vis[N];

bool operator < (const Edge &x,const Edge &y) {return x.w > y.w;}

void dijkstra() {
	memset(dis,0x3f,sizeof dis);
	priority_queue<Edge> q;
	dis[1] = 0;
	q.push({1,dis[1]});
	while (!q.empty()) {
		int u = q.top().v; q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto [v,w] : G[u]) {
			if (vis[v]) continue;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push({v,dis[v]});
			}
		}
	}
}

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        G[a].push_back({b,c}); G[b].push_back({a,c});
    }
    dijkstra();
    cout << dis[n] << endl;
    return 0;
}