#include<iostream>
#include<vector>
using namespace std;

const int N = 2e5 + 5;
struct Edge {int u,v;} a[N];
vector<int> G[N];
int dep[N];
long long ans[N],d[N];

void dfs(int u,int pa) {
    dep[u] = dep[pa] + 1;
    for (auto v : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
    }
}

void add(int u,int pa,long long sum) {
    ans[u] = sum + d[u];
    for (auto v : G[u]) {
        if (v == pa) continue;
        add(v,u,ans[u]);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1;i < n;i++) {
        cin >> a[i].u >> a[i].v;
        G[a[i].u].push_back(a[i].v); G[a[i].v].push_back(a[i].u);
    }
    dfs(1,0);
    int q;
    cin >> q;
    while (q--) {
        int op,e,k;
        cin >> op >> e >> k;
        int u = a[e].u,v = a[e].v;
        int father,child;
        if (dep[u] > dep[v]) father = v,child = u;
        else father = u,child = v;
        if (op == 1)
            if (father == u) d[1] += k,d[v] -= k;
            else d[u] += k;
        else
            if (father == v) d[1] += k,d[u] -= k;
            else d[v] += k;
    }
    add(1,0,0);
    for (int i = 1;i <= n;i++) cout << ans[i] << endl;
    return 0;
}