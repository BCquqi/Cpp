#include<iostream>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;

const int N = 5e4 + 5;
vector<int> G[N];
int w[N],siz[N],mxs[N],dep[N];

void init(int u,int pa) {
    siz[u] = w[u];
    for (auto v : G[u]) {
        if (v == pa) continue;
        init(v,u);
        siz[u] += siz[v], mxs[u] = max(mxs[u],siz[v]);
    }
    return ;
}

void dfs(int u,int pa) {
    dep[u] = dep[pa] + 1;
    for (auto v : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
    }
}

signed main() {
    freopen("hubroute.in","r",stdin);
    freopen("hubroute.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> w[i];
    for (int i = 1;i < n;i++) {
        int a,b;
        cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    init(1,0);
    int heavy = 0,mnsiz = 1e18;
    for (int i = 1;i <= n;i++) {
        if (max(siz[1] - siz[i],mxs[i]) < mnsiz)
            mnsiz = max(siz[1] - siz[i],mxs[i]), heavy = i;
    }
    dep[0] = -1;
    dfs(heavy,0);
    long long ans = 0;
    for (int i = 1;i <= n;i++) ans += w[i] * dep[i];
    cout << ans << endl;
    return 0;
}