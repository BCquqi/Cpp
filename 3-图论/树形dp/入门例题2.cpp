#include<iostream>
#include<vector>
#define int long long
using namespace std;

const int N = 1e5 + 5;
vector<int> G[N];
int sum[N],maxn[N],d[N];

void dfs(int u,int pa) {
    maxn[u] = d[u], sum[u] = d[u];
    for (auto v : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
        sum[u] += sum[v];
        maxn[u] = max(maxn[u],maxn[v]);
    }
    return ;
}

signed main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> d[i];
    for (int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1,0);
    for (int i = 1;i <= n;i++) cout << sum[i] << ' ';
    cout << endl;
    for (int i = 1;i <= n;i++) cout << maxn[i] << ' ';
    cout << endl;
    return 0;
}