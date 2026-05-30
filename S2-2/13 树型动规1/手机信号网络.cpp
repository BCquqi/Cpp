#include<iostream>
#include<vector>
using namespace std;

const int N = 1e4 + 5;
int dp[N][3];
vector<int> G[N];

void dfs(int u,int pa) {
    bool flag = true;
    int minn = 1e9;
    dp[u][0] = 1;
    for (auto v : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
        dp[u][0] += min(dp[v][0],min(dp[v][1],dp[v][2]));
        dp[u][1] += min(dp[v][0],dp[v][2]);
        dp[u][2] += min(dp[v][0],dp[v][2]);
        if (dp[v][0] <= dp[v][2]) flag = false;
        minn = min(minn,dp[v][0] - dp[v][2]);
    }
    if (flag) dp[u][2] += minn;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1;i < n;i++) {
        int a,b;
        cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    dfs(1,0);
    cout << min(dp[1][0],dp[1][2]) << endl;
    return 0;
}