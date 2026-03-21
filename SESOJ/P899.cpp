#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1e5 + 5;
struct Edge {int v,w;};
vector<Edge> G[N];
int dp[N];

void dfs(int u,int pa) {
    for (auto [v,w] : G[u]) {
        if (v == pa) continue;
        dp[v] = dp[u] + w;
        dfs(v,u);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1;i < n;i++) {
        int x,y,z;
        cin >> x >> y >> z;
        G[x].push_back({y,z});G[y]. push_back({x,z});
    }
    for (int i = 1;i <= n;i++) {
        memset(dp,0,sizeof dp);
        dfs(i,0);
        int ans = 0;
        for (int j = 1;j <= n;j++) ans += dp[j];
        cout << ans << endl;
    }
    return 0;
}