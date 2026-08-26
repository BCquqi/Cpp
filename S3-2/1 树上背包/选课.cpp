#include<iostream>
#include<vector>
using namespace std;

const int N = 105;
int n,m,sc[N],dp[N][N];
vector<int> G[N];
// dp[i][j] 表示以 i 为根的子树中，选课数量为 j 的最大学分

void dfs(int u,int pa) {
    for (auto v : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
        for (int j = m;j >= 1;j--)
            for (int k = 0;k < j;k++)
                dp[u][j] = max(dp[u][j],dp[u][j - k] + dp[v][k]);
    }
}

int main() {
    cin >> n >> m;
    m++;
    for (int i = 1;i <= n;i++) {
        int u;
        cin >> u >> sc[i];
        G[u].push_back(i); G[i].push_back(u);
        dp[i][1] = sc[i];
    }
    dfs(0,-1);
    cout << dp[0][m] << endl;
    return 0;
}