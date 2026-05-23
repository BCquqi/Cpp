#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 3e5 + 5;
struct Edge {int v,w;};
struct Path {int u,v,dis,lca;} path[N];
vector<Edge> G[N];
long long dis[N],fa[N][32],dep[N],edge[N],d[N],a[N],n,m;

void dfs(int u,int pa) {
    dep[u] = dep[pa] + 1;
    fa[u][0] = pa;
    for (int i = 1;i <= 30;i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (auto [v,w] : G[u]) {
        if (v == pa) continue;
        dis[v] = dis[u] + w;
        edge[v] = w;
        dfs(v,u);
    }
}

int LCA(int u,int v) {
    if (dep[u] < dep[v]) swap(u,v);
    for (int i = 30;i >= 0;i--)
        if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
    if (u == v) return u;
    for (int i = 30;i >= 0;i--)
        if (fa[u][i] != fa[v][i]) u = fa[u][i],v = fa[v][i];
    return fa[u][0];
}

int dist(int u,int v) {return dis[u] + dis[v] - 2 * dis[LCA(u,v)];}

void add(int u,int pa) {
    a[u] = d[u];
    for (auto [v,w] : G[u]) {
        if (v == pa) continue;
        add(v,u);
        a[u] += a[v];
    }
}

bool check(int mid) {
    memset(d,0,sizeof d);
    int cnt = 0,maxn = 0;
    for (int i = 1;i <= m;i++)
        if (path[i].dis > mid) {
            cnt++;
            d[path[i].u]++;
            d[path[i].v]++;
            d[path[i].lca] -= 2;
            maxn = max(maxn,path[i].dis);
        }
    if (cnt == 0) return true;
    memset(a,0,sizeof a);
    add(1,0);
    for (int i = 2;i <= n;i++)
        if (a[i] >= cnt && maxn - edge[i] <= mid) return true;
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 1;i < n;i++) {
        int a,b,t;
        cin >> a >> b >> t;
        G[a].push_back({b,t}); G[b].push_back({a,t});
    }
    dfs(1,0);
    for (int i = 1;i <= m;i++) {
        cin >> path[i].u >> path[i].v;
        path[i].dis = dist(path[i].u,path[i].v),path[i].lca = LCA(path[i].u,path[i].v);
    }
    sort(path + 1,path + m + 1,[](Path x,Path y) {return x.dis < y.dis;});
    int L = 0,R = 3e8;
    long long ans = 0;
    while (L <= R) {
        int mid = (L + R) >> 1;
        if (check(mid)) R = mid - 1,ans = mid;
        else L = mid + 1;
    }
    cout << ans << endl;
    return 0;
}