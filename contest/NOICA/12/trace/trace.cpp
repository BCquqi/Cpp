#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
#define int long long
using namespace std;

const int maxn = 1e5 + 5,mod = 1e9 + 7;
const long long inf = 1e18;
int n,m,eu[maxn],ev[maxn],ew[maxn];
string p;
struct Edge {int v,w;};
vector<Edge> G[maxn],rG[maxn];
int dis1[maxn],dis2[maxn],cnt1[maxn],cnt2[maxn];
bool vis[maxn];

bool operator < (const Edge &x,const Edge &y) {return x.w > y.w;}

void dijkstra(int s,vector<Edge> G[],long long dis[],long long cnt[]) {
    fill(dis,dis + n + 1,inf);
    memset(vis,0,sizeof vis);
    for (int i = 1;i <= n;i++) cnt[i] = 0;
    priority_queue<Edge> q;
    dis[s] = 0, cnt[s] = 1;
    q.push({s,dis[s]});
    while (!q.empty()) {
        int u = q.top().v; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto p : G[u]) {
            int v = p.v,w = p.w;
            if (vis[v]) continue;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w, cnt[v] = cnt[u];
                q.push({v,dis[v]});
            }
            else if (dis[v] == dis[u] + w) cnt[v] = (cnt[v] + cnt[u]) % mod;
        }
    }
}

signed main() {
    freopen("trace.in","r",stdin);
    freopen("trace.out","w",stdout);
    cin >> n >> m >> p;
    for (int i = 0;i < m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        eu[i] = u; ev[i] = v; ew[i] = w;
        G[u].push_back({v,w});
        rG[v].push_back({u,w});
    }
    dijkstra(1,G,dis1,cnt1);
    dijkstra(2,rG,dis2,cnt2);
    cout << dis1[2] << endl;
    for (int i = 0;i < m;i++) {
        if (p[i] == '0') {
            cout << "SOSO" << endl;
            continue;
        }
        int u = eu[i],v = ev[i],w = ew[i];
        long long val = inf;
        if (dis1[v] < inf && dis2[u] < inf) val = dis1[v] + w + dis2[u];
        if (val < dis1[2]) cout << "HAPPY" << endl;
        else if (val > dis1[2]) {
            bool flag = false;
            if (dis1[u] < inf && dis2[v] < inf && dis1[u] + w + dis2[v] == dis1[2])
                if ((cnt1[u] * cnt2[v]) % mod == cnt1[2]) flag = true;
            if (flag) cout << "SAD" << endl;
            else cout << "SOSO" << endl;
        }
        else cout << "SOSO" << endl;
    }
    return 0;
}