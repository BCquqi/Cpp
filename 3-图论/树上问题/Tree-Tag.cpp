#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int N = 1e5 + 5;
vector<int> G[N];
int n,a,b,da,db;
int dep[N];

void dfs(int u,int pa) {
    dep[u] = dep[pa] + 1;
    for (auto v : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
    }
}

void solve() {
    cin >> n >> a >> b >> da >> db;
    for (int i = 1;i <= n;i++) G[i].clear();
    memset(dep,0,sizeof dep);
    for (int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
    }
    if (2 * da >= db) {
        cout << "Alice" << endl;
        return ;
    }
    dfs(1,0);
    int s,mxdep = 0;
    for (int i = 1;i <= n;i++)
        if (mxdep < dep[i]) mxdep = dep[i], s = i;
    memset(dep,0,sizeof dep);
    dfs(s,0);
    int dia = 0;
    for (int i = 1;i <= n;i++)
        if (dia < dep[i]) dia = dep[i];
    --dia;
    if (da * 2 >= dia) {
        cout << "Alice" << endl;
        return ;
    }
    memset(dep,0,sizeof dep);
    dfs(a,0);
    if (dep[b] - 1 <= da) {
        cout << "Alice" << endl;
        return ;
    }
    cout << "Bob" << endl;
    return ;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}