#include<iostream>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;

const int N = 3e5 + 5;
int a[N],dp[N],siz[N];
vector<int> G[N];

void dfs(int u,int pa) {
    siz[u] = 1;
    for (auto v : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
        siz[u] += siz[v];
    }
    sort(G[u].begin(),G[u].end(),[](int u,int v) {return max(dp[u],2LL * siz[u] + dp[v]) < max(dp[v],2LL * siz[v] + dp[u]);});
    int maxn = a[u],cur = 0;
    for (auto v : G[u]) {
        if (v == pa) continue;
        maxn = max(maxn,1LL + cur + dp[v]);
        cur += 2 * siz[v];
    }
    dp[u] = maxn;
    return ;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("traverse.in","r",stdin);
    freopen("traverse.out","w",stdout);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1,0);
    cout << max(dp[1],2LL * (n - 1) + a[1]) << endl;
    return 0;
}

完全学习模仿当前码风写代码。