#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int N = 2e5 + 5;
struct Edge {int v,w;};
vector<Edge> G[N];
int dis[N],p[N],siz[N];
long long dp[N];

void dfs(int u,int pa) {
    siz[u] = p[u];
    for (auto [v,w] : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
        siz[u] += siz[v];
        dp[u] += dp[v] + 1ll * siz[v] * w;
    }
}

void change(int u,int pa) {
    for (auto [v,w] : G[u]) {
        if (v == pa) continue;
        dp[v] = dp[u] + 1ll * (siz[1] - 2 * siz[v]) * w;
        change(v,u);
    }
}

int main() {
    int n,id = 0;;
    long long ans = 1e18;
    cin >> n;
    for (int i = 1;i < n;i++) {
        int a,b,l;
        cin >> a >> b >> l;
        G[a].push_back({b,l}); G[b].push_back({a,l});
    }
    for (int i = 1;i <= n;i++) cin >> p[i];
    dfs(1,0);
    change(1,0);
    for (int i = 1;i <= n;i++)
        if (ans > dp[i]) id = i,ans = dp[i];
    cout << id << endl << ans << endl;
    return 0;
}