#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5 + 5;
int dp[N][25],c[N],n,k;
vector<int> G[N];

void dfs1(int u,int pa) {
    dp[u][0] = c[u];
    for (auto v : G[u]) {
        if (v == pa) continue;
        dfs1(v,u);
        for (int j = 1;j <= k;j++)
            dp[u][j] += dp[v][j - 1];
    }
}

void dfs2(int u,int pa) {
    for (auto v : G[u]) {
        if (v == pa) continue;
        int tmp[25] = {0};
        tmp[0] = dp[v][0];
        for (int j = 1;j <= k;j++) {
            tmp[j] = dp[v][j];
            int p = dp[u][j - 1];
            if (j >= 2)
                p -= dp[v][j - 2];
            tmp[j] += p;
        }
        for (int j = 0;j <= k;j++)
            dp[v][j] = tmp[j];
        dfs2(v,u);
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v); G[v].push_back(u);
    }
    for (int i = 1;i <= n;i++) cin >> c[i];
    dfs1(1,0);
    dfs2(1,0);
    for (int i = 1;i <= n;i++) {
        int sum = 0;
        for (int j = 0;j <= k;j++) sum += dp[i][j];
        cout << sum << endl;
    }
    return 0;
}