#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define int long long
using namespace std;

const int N = 25,M = 100005;
int n,K,e,start,tot = 0;
int d[N][N],l[N],r[N];
int tim[N][1005],cnt[N];
int id[N][1005][2],dis[M];

struct Edge {int v,w;};
struct Node {int cost,u;};
bool operator < (const Node &x,const Node &y) {return x.cost > y.cost;}
vector<Edge> G[M];
priority_queue<Node> q;

void floyd() {
    for (int k = 0;k < n;k++)
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                if (d[i][k] != 0x3f3f3f3f && d[k][j] != 0x3f3f3f3f)
                    d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
    return ;
}

void dijkstra(int s) {
    memset(dis,0x3f,sizeof dis);
    dis[s] = 0;
    q.push({0,s});
    while (!q.empty()) {
        Node cur = q.top(); q.pop();
        int c = cur.cost,u = cur.u;
        if (c != dis[u]) continue;
        for (auto p : G[u]) {
            int v = p.v,w = p.w;
            if (dis[v] > c + w) {
                dis[v] = c + w;
                q.push({dis[v],v});
            }
        }
    }
    return ;
}

signed main() {
    freopen("go.in","r",stdin);
    freopen("go.out","w",stdout);
    cin >> n >> K;
    for (int i = 1;i <= K;i++) cin >> l[i];
    for (int i = 1;i <= K;i++) cin >> r[i];
    cin >> start >> e;

    memset(d,0x3f,sizeof d);
    for (int i = 0;i < n;i++) d[i][i] = 0;
    for (int i = 1;i <= e;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v],w), d[v][u] = min(d[v][u],w);
    }
    floyd();

    for (int i = 0;i < n;i++) {
        cnt[i] = 0, tim[i][++cnt[i]] = 0;
        for (int k = 1;k <= K;k++) {
            tim[i][++cnt[i]] = l[k], tim[i][++cnt[i]] = r[k];
            for (int j = 0;j < n;j++) {
                if (d[j][i] != 0x3f3f3f3f3f3f3f3f && l[k] + d[j][i] <= r[k]) 
                    tim[i][++cnt[i]] = l[k] + d[j][i];
                if (d[i][j] != 0x3f3f3f3f3f3f3f3f && r[k] - d[i][j] >= l[k]) 
                    tim[i][++cnt[i]] = r[k] - d[i][j];
            }
        }
        sort(tim[i] + 1,tim[i] + cnt[i] + 1);
        cnt[i] = unique(tim[i] + 1,tim[i] + cnt[i] + 1) - tim[i] - 1;
        for (int j = 1;j <= cnt[i];j++)
            id[i][j][0] = ++tot, id[i][j][1] = ++tot;
    }

    for (int i = 0;i < n;i++)
        for (int j = 1;j <= cnt[i];j++) {
            G[id[i][j][0]].push_back({id[i][j][1],start});
            G[id[i][j][1]].push_back({id[i][j][0],0});
            if (j < cnt[i]) {
                int dt = tim[i][j + 1] - tim[i][j];
                G[id[i][j][0]].push_back({id[i][j + 1][0],dt});
                G[id[i][j + 1][1]].push_back({id[i][j][1],dt});
            }
        }

    for (int i = 0;i < n;i++)
        for (int j = i + 1;j < n;j++) {
            if (d[i][j] == 0x3f3f3f3f) continue;
            for (int k = 1;k <= K;k++)
                if (l[k] + d[i][j] <= r[k]) {
                    int u1 = id[i][lower_bound(tim[i] + 1,tim[i] + cnt[i] + 1,l[k]) - tim[i]][0], 
                        v1 = id[j][lower_bound(tim[j] + 1,tim[j] + cnt[j] + 1,l[k] + d[i][j]) - tim[j]][0];
                    G[u1].push_back({v1,d[i][j]});

                    int u2 = id[j][lower_bound(tim[j] + 1,tim[j] + cnt[j] + 1,l[k]) - tim[j]][0], 
                        v2 = id[i][lower_bound(tim[i] + 1,tim[i] + cnt[i] + 1,l[k] + d[i][j]) - tim[i]][0];
                    G[u2].push_back({v2,d[i][j]});

                    int u3 = id[i][lower_bound(tim[i] + 1,tim[i] + cnt[i] + 1,r[k] - d[i][j]) - tim[i]][0], 
                        v3 = id[j][lower_bound(tim[j] + 1,tim[j] + cnt[j] + 1,r[k]) - tim[j]][0];
                    G[u3].push_back({v3,d[i][j]});

                    int u4 = id[j][lower_bound(tim[j] + 1,tim[j] + cnt[j] + 1,r[k] - d[i][j]) - tim[j]][0], 
                        v4 = id[i][lower_bound(tim[i] + 1,tim[i] + cnt[i] + 1,r[k]) - tim[i]][0];
                    G[u4].push_back({v4,d[i][j]});
                }
        }

    int s = id[0][lower_bound(tim[0] + 1,tim[0] + cnt[0] + 1,0) - tim[0]][0];
    dijkstra(s);

    long long ans = 0x3f3f3f3f3f3f3f3f;
    for (int j = 1;j <= cnt[n - 1];j++)
        ans = min(ans,dis[id[n - 1][j][0]]);
    if (ans == 0x3f3f3f3f3f3f3f3f) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}