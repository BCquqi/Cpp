#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int N = 1005;
vector<int> G[N];
bool vis[N];
int match[N];
int n,m,e;

bool dfs(int u) {
    for (auto v : G[u]) {
        if (vis[v]) continue;
        vis[v] = true;
        if (!match[v] || dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> m >> e;
    for (int i = 1;i <= e;i++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    int ans = 0;
    for (int i = 1;i <= n;i++) {
        memset(vis,0,sizeof vis);
        if (dfs(i)) ans++;
    }
    cout << ans << endl;
    return 0;
}