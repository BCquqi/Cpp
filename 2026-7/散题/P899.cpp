#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1e5 + 5;
struct Edge {long long v,w;};
vector<Edge> G[N];
long long dp[N],s[N],ans[N],n;

void dfs(long long u,long long pa) {
    s[u] = 1;
    for (auto [v,w] : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
        s[u] += s[v];
        dp[u] += dp[v] + s[v] * w;
    }
}

void change(long long u,long long pa) {
    for (auto [v,w] : G[u]) {
        if (v == pa) continue;
        ans[v] = ans[u] + (n - 2 * s[v]) * w;
        change(v,u);
    }
}

int main() {
    cin >> n;
    for (int i = 1;i < n;i++) {
        long long x,y,z;
        cin >> x >> y >> z;
        G[x].push_back({y,z});G[y]. push_back({x,z});
    }
    dfs(1,0);
    ans[1] = dp[1];
    change(1,0);
    for (int i = 1;i <= n;i++) cout << ans[i] << endl;
    return 0;
}