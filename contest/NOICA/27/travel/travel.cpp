#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 2e5 + 5;
struct Edge {int v,w;};
vector<Edge> G[N];
int n,m,s,t;
int dis[N],it[N];

bool operator < (const Edge &x,const Edge &y) {return x.w > y.w;}

bool check(int mid) {
    memset(dis,0x3f,sizeof dis);
    memset(it,0,sizeof it);
    queue<int> q;
    dis[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        while (it[u] < (int)G[u].size() && G[u][it[u]].w <= mid - dis[u]) {
            int v = G[u][it[u]].v,w = G[u][it[u]].w;
            if (w < dis[v]) dis[v] = w,q.push(v);
            it[u]++;
        }
    }
    return dis[t] != 0x3f3f3f3f;
}

int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> n >> m >> s >> t;
    for (int i = 1;i <= m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        G[u].push_back({v,w});
    }
    for (int i = 1;i <= n;i++) sort(G[i].begin(),G[i].end(),[](const Edge &a,const Edge &b){return a.w < b.w;});
    int l = 1,r = 2e9,ans = -1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}