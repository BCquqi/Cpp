#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<map>
using namespace std;

const int N = 1e4 + 5;
struct Edge {int v,w;};
vector<Edge> G[N];
map<pair<int,int>,int> mp;
int dis[N],vis[N],a,b,n,m,d;

bool operator < (const Edge &x,const Edge &y) {return x.w > y.w;}

void dijkstra() {
	memset(dis,0x3f,sizeof dis);
    memset(vis,false,sizeof vis);
	priority_queue<Edge> q;
	dis[a] = 0;
	q.push({a,dis[a]});
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

void solve() {
    for (int i = 0;i < N;i++) G[i].clear();
    mp.clear();
    for (int i = 1;i <= m;i++) {
        int u,v,c;
        cin >> u >> v >> c;
        mp[{u,v}] = c;
    }
    cin >> d;
    for (int i = 1;i <= d;i++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back({v,mp[{u,v}]}); G[v].push_back({u,mp[{u,v}]});
        mp.erase({u,v});
    }
    for (auto x : mp) {G[x.first.first].push_back({x.first.second,0}); G[x.first.second].push_back({x.first.first,0});}
    cin >> a >> b;
    dijkstra();
    cout << ((dis[b] == 0x3f3f3f3f) ? -1 : dis[b]) << endl;
    return ;
}

int main() {
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        solve();
    }
    return 0;
}