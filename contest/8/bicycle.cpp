#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int N = 1e5 + 5;
int n,m,s,alt[N],dis[N];
bool vis[N];
struct Edge {int v,w,diff;};
vector<Edge> G[N];

bool operator < (const Edge &x,const Edge &y) {return x.w > y.w;}

bool check(int mid) {
    memset(vis,0,sizeof vis);
    memset(dis,0x3f,sizeof dis);
    priority_queue<Edge> q;
    dis[1] = 0;
    q.push({1,dis[1]});
    while (!q.empty()) {
        int u = q.top().v; q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto p : G[u]) {
            int v = p.v,w = p.w,diff = p.diff;
            if (diff > mid) continue;
            if (vis[v]) continue;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({v,dis[v]});
            }
        }
    }
    return dis[n] <= s;
}

int main() {
    freopen("bicycle.in","r",stdin);
    freopen("bicycle.out","w",stdout);
    cin >> n >> m >> s;
    for (int i = 1;i <= n;i++) cin >> alt[i];
    int l = 1e9,r = -1e9;
    for (int i = 1;i <= m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        G[u].push_back({v,w,alt[v] - alt[u]});
        G[v].push_back({u,w,alt[u] - alt[v]});
        l = min(l,min(alt[u] - alt[v],alt[v] - alt[u])), 
        r = max(r,max(alt[u] - alt[v],alt[v] - alt[u]));
    }
    // 思路：最小化最大坡度且使得满足最短路不超过S，即瓶颈最短路，采用二分答案
    int ans = -1e9;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    if (ans == -1e9) cout << "NO" << endl;
    else cout << ans << endl;
    return 0;
}