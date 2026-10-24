#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int N = 1e5 + 5, M = 2;
struct Edge {int v, w;};
vector<Edge> G[N];
int s[N];
int ch[32 * N][M], id = 1;

void dfs (int u, int pa) {
    for (auto [v,w] : G[u]) {
        if (v == pa) continue;
        s[v] = s[u] ^ w;
        dfs(v, u);
    }
    return ;
}

void insert(int s) {
    int x = 1;
    for (int cur = 30; cur >= 0; cur--) {
        bool i = (s >> cur) & 1;
        if (!ch[x][i]) ch[x][i] = ++id;
        x = ch[x][i];
    }
}

int query(int s) {
    int x = 1, ret = 0;
    for (int cur = 30; cur >= 0; cur--) {
        bool i = (s >> cur) & 1;
        if (ch[x][!i]) ret |= (1 << cur), x = ch[x][!i];
        else x = ch[x][i];
    }
    return ret;
}

signed main () {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w}), G[v].push_back({u, w});
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) insert(s[i]);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, query(s[i]));
    cout << ans << endl;
    return 0;
}