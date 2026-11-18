#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;

const int N = 3e4 + 5;
int n,dep[N],rt,siz[N],tmp,depth,tot,ans = 0;
bool vis[N];
vector<int> G[N];

int interact(int u,int k) {
    cout << "? " << u << " " << k << endl;
    int o;
    cin >> o;
    return o;
}

void dfs(int u) {
    siz[u] = 1;
    for (auto v : G[u]) {
        if (vis[v]) continue;
        dfs(v);
        siz[u] += siz[v];
    }
    if (dep[u] <= depth && max(siz[u],tot - siz[u]) < tmp)
        ans = u, tmp = max(siz[u],tot - siz[u]);
}

void solve() {
    cin >> n;
    rt = 1, tot = n;
    memset(vis,0,sizeof vis);
    memset(dep,0,sizeof dep);
    for (int i = 1;i <= n;i++) G[i].clear();
    int l = 0,r = 0;
    for (int i = 2;i <= n;i++) {
        int u;
        cin >> u;
        G[u].push_back(i);
        dep[i] = dep[u] + 1;
        r = max(r,dep[i]);
    }
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (interact(1,mid)) r = mid - 1, depth = mid;
        else l = mid + 1;
    }
    while (true) {
        tmp = n + 1;
        dfs(rt);
        if (interact(ans,depth - dep[ans])) {
            rt = ans, tot = siz[ans];
            if (dep[ans] == depth) break;
        }
        else vis[ans] = 1;
    }
    cout << "! " << ans << endl;
    return ;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}