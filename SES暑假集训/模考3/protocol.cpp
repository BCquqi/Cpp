#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N = 1e4 + 5;
struct Edge {int v; long long w;};
struct Node {int value,id;};
vector<Edge> G[N];
int p[N],r[N];
long long d[25][N],t[N]; // t 记录最短路
bool vis[N];
map<int,Node> mp; // 通过以 g 为下标查询f，查询时要注意是否存在

bool operator < (const Edge &x,const Edge &y) {return x.w > y.w;}

void dijkstra(int s,long long dis[]) {
	for (int i = 1;i <= N;i++) dis[i] = 1e18;
	memset(vis,false,sizeof vis);
	priority_queue<Edge> q;
	dis[s] = 0;
	q.push({s,dis[s]});
	while (!q.empty()) {
		int u = q.top().v; q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto [v,w] : G[u]) {
			if (vis[v]) continue;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push({v,dis[v]});
			}
		}
	}
}

void solve(int i) {
    int u = p[i],type = r[i]; // u是起点，type用于匹配终点
    if (mp.find(type) == mp.end()) {
        t[i] = 1e18;
        return ;
    }
    int v = mp[type].value,id = mp[type].id; // 匹配终点和最短路
    t[i] = d[id][u];
    return ;
}

int main() {
    freopen("protocol.in","r",stdin);
    freopen("protocol.out","w",stdout);
    int n,m,q,k,ans = 0;
    long long T;
    cin >> n >> m >> q >> k >> T;
    for (int i = 1;i <= m;i++) {
        int x,y,w;
        cin >> x >> y >> w;
        G[x].push_back({y,w}); G[y].push_back({x,w});
    }
    for (int i = 1;i <= q;i++) cin >> p[i] >> r[i];
    for (int i = 1;i <= k;i++) {
        int f,g;
        cin >> f >> g;
        mp[g] = {f,i};
        dijkstra(f,d[i]);
    }
    for (int i = 1;i <= q;i++) solve(i);
    sort(t + 1,t + q + 1);
    for (int i = 1;T - t[i] >= 0 && i <= q;i++) ans++,T -= t[i];
    cout << ans << endl;
    return 0;
}