#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 5e4 + 5;
struct Edge {int v,w;};
vector<Edge> G[N],G2[N];
int a[15],dis[N],dist[15][15],dp[1 << 15][15];
// dp[S][i] 含义: 经过点集 S，当前在 i 的最短路
bool vis[N];
int n,m,k,s,t;

bool operator < (const Edge &x,const Edge &y) {return x.w > y.w;}

void dijkstra(int s,int dis[],bool vis[],vector<Edge> G[]) {
    for (int i = 1;i <= n;i++) dis[i] = 1e9, vis[i] = 0;
    priority_queue<Edge> q;
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
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k >> s >> t;
    for (int i = 1;i <= m;i++) {
        int x,y,z;
        cin >> x >> y >> z;
        G[x].push_back({y,z});
    }
    a[1] = s;
    for (int i = 2;i <= k + 1;i++) cin >> a[i];
    a[k + 2] = t;
    memset(dist,-1,sizeof dist);
    for (int i = 1;i <= k + 2;i++) {
        dijkstra(a[i],dis,vis,G);
        for (int j = 1;j <= k + 2;j++)
            dist[i][j] = dis[a[j]];
    }
    memset(dp,0x3f,sizeof dp);
    for (int i = 1;i <= k;i++)
        dp[0][i] = dist[1][i + 1];
    for (int s = 0;s < (1 << k);s++)
        for (int i = 1;i <= k;i++) {
            if ((s >> (i - 1)) & 1 == 0) continue;
            for (int j = 1;j <= k;j++) {
                if ((s >> (j - 1)) & 1) continue;
                dp[s | (1 << (j - 1))][j] = min(dp[s | (1 << (j - 1))][j],dp[s][i] + dist[i + 1][j + 1]);
            }
        }
    int ans = 1e9;
    for (int i = 1;i <= k;i++)
        ans = min(ans,dp[(1 << k) - 1][i] + dist[i + 1][k + 2]);
    cout << (ans == 1e9 ? -1 : ans) << endl;
    return 0;
}