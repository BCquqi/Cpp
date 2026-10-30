#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5 + 5;
struct Edge {int v,w;};
vector<Edge> G[N];
int dep[N],fa[N][32],da[N],db[N],sa[N],sb[N],fw[N],a[N],b[N],cnt[N];
long long dis[N];

void init(int u,int pa) {
    fa[u][0] = pa;
    for (int i = 1;i <= 30;i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (auto [v,w] : G[u]) {
        if (v == pa) continue;
        fw[v] = w;
        dis[v] = dis[u] + w, dep[v] = dep[u] + 1;
        init(v,u);
    }
}

void dfs(int u,int pa) {
    sa[u] = da[u];
    sb[u] = db[u];
    for (auto [v,w] : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
        sa[u] += sa[v];
        sb[u] += sb[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,l,m;
    cin >> n >> l >> m;
    for (int i = 1;i < n;i++) {
        int x,y,z;
        cin >> x >> y >> z;
        G[x].push_back({y,z}), G[y].push_back({x,z});
    }
    dis[1] = 0, dep[1] = 1;
    init(1,0);
    for (int i = 1;i <= m;i++) {
        cin >> a[i] >> b[i];
        da[a[i]]++, db[b[i]]++;
    }
    dfs(1,0);
    long long tot = 0;
    for (int u = 2;u <= n;u++) {
        int sum = sb[u] - sa[u];
        if (sum == 0)
            {if (sb[u] > 0) tot += 2ll * fw[u];}
        else
            cnt[u] = (sum + l - 1) / l, 
            tot += 2ll * cnt[u] * fw[u];
    }
    long long mx = 0;
    for (int i = 1;i <= n;i++)
        if (sb[i] > 0)
            mx = max(mx, dis[i]);
    cout << tot - mx << endl;
    return 0;
}