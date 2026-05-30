#include<iostream>
#include<vector>
using namespace std;

const int N = 6e3 + 5;
int r[N],dp[N][2];
bool flag[N];
vector<int> G[N];

void dfs(int u,int pa) {
    for (auto v : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
        dp[u][0] += max(dp[v][0],dp[v][1]);
        dp[u][1] += dp[v][0];
    }
    dp[u][1] += r[u];
}

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> r[i];
    for (int i = 1;i < n;i++) {
        int l,k;
        cin >> l >> k;
        G[l].push_back(k); G[k].push_back(l);
    }
    dfs(1,0);
    cout << max(dp[1][0],dp[1][1]) << endl;
    return 0;
}