#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 2e5 + 5;
struct Node {int u,v,len,w;} a[2 * N];
struct Edge {int v,len,w;}; // 长度为 len，海拔为 w
vector<Edge> G[N];
vector<int> tree[2 * N];

int dis[2 * N],vis[N],n,m,f[2 * N],cnt,dep[2 * N],fa[2 * N][32],treew[2 * N];

bool operator < (const Edge &x,const Edge &y) {return x.len > y.len;}

void dijkstra() {
    memset(dis,0x3f,sizeof dis);
    priority_queue<Edge> q;
    dis[1] = 0;
    q.push({1,dis[1]});
    while (!q.empty()) {
        int u = q.top().v; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto p : G[u]) {
            int v = p.v,len = p.len;
            if (vis[v]) continue;
            if (dis[v] > dis[u] + len) {
                dis[v] = dis[u] + len;
                q.push({v,dis[v]});
            }
        }
    }
}

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}

void kruskal() {
    sort(a + 1,a + m + 1,[](Node x,Node y) {return x.w > y.w;});
    for (int i = 1;i <= 2 * n;i++) f[i] = i;
    cnt = n;
    for (int i = 1;i <= m;i++) {
        int u = a[i].u,v = a[i].v;
        if (find(u) == find(v)) continue;
        cnt++;
        tree[cnt].push_back(find(u)); tree[find(u)].push_back(cnt);
        tree[cnt].push_back(find(v)); tree[find(v)].push_back(cnt);
        f[find(u)] = f[find(v)] = cnt, treew[cnt] = a[i].w;
    }
}

void dfs(int u,int pa) {
    dep[u] = dep[pa] + 1;
    fa[u][0] = pa;
    for (int i = 1;i <= 30;i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (auto v : tree[u]) {
        if (v == pa) continue;
        dfs(v,u);
        dis[u] = min(dis[u],dis[v]);
    }
}

int query(int x,int y) {
    for (int i = 30;i >= 0;i--)
        if (dep[x] > (1 << i) && treew[fa[x][i]] > y) x = fa[x][i];
    return dis[x];
}

void solve() {
    for (int i = 1;i <= N;i++) G[i].clear();
    for (int i = 1;i <= 2 * N;i++) tree[i].clear();
    memset(vis,0,sizeof vis); memset(f,0,sizeof f); memset(dep,0,sizeof dep); memset(fa,0,sizeof fa);
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        cin >> a[i].u >> a[i].v >> a[i].len >> a[i].w;
        G[a[i].u].push_back({a[i].v,a[i].len,a[i].w});
        G[a[i].v].push_back({a[i].u,a[i].len,a[i].w});
    }
    dijkstra();
    kruskal();
    dfs(cnt,0);
    int q,k,s,lastans = 0;
    cin >> q >> k >> s;
    while (q--) {
        int v0,p0;
        cin >> v0 >> p0;
        v0 = (k * lastans + v0 - 1) % n + 1, p0 = (k * lastans + p0) % (s + 1);
        lastans = query(v0,p0);
        cout << lastans << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}