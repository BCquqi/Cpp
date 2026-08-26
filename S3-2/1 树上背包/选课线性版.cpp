#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5 + 5;
int n,m,sc[N],dp[N][305],siz[N],tim = 0,val[N],dfn[N];
vector<int> G[N];

void dfs(int u,int pa) {
    int id = ++tim;
    val[id] = sc[u];
    siz[id] = 1;
    for (auto v : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
        siz[id] += siz[dfn[v]];
    }
    dfn[u] = id;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        int u;
        cin >> u >> sc[i];
        G[u].push_back(i); G[i].push_back(u);
    }
    dfs(0,-1);
    for (int i = n + 1;i >= 1;i--)
        for (int j = 1;j <= m + 1;j++) {
            int nxt = i + siz[i];
            if (nxt > n) dp[i][j] = 0;
            else dp[i][j] = dp[nxt][j];
            dp[i][j] = max(dp[i][j],dp[i + 1][j - 1] + val[i]);
        }
    cout << dp[1][m + 1] << endl;
    return 0;
}