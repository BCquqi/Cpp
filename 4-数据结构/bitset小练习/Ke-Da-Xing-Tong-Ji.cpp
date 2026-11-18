#include<iostream>
#include<algorithm>
#include<bitset>
#include<vector>
using namespace std;

const int N = 3e4 + 5;
vector<int> G[N];
bitset<N> a[N];
bool vis[N];

void dfs(int u) {
    if (vis[u]) return ;
    vis[u] = true;
    for (auto v : G[u]) {
        dfs(v);
        a[u] |= a[v];
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    for (int i = 1;i <= n;i++) a[i][i] = 1;
    for (int i = 1;i <= n;i++) {
        dfs(i);
        cout << a[i].count() << endl;
    }
    return 0;
}