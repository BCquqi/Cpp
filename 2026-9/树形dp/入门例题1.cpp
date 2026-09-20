#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5 + 5;
vector<int> G[N];
int siz[N],dep[N];

void dfs(int u,int pa) {
    siz[u] = 1;
    for (auto v : G[u]) {
        if (v == pa) continue;
        dep[v] = dep[u] + 1;
        dfs(v,u);
        siz[u] += siz[v];
    }
    return ;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1,0);
    for (int i = 1;i <= n;i++) cout << "#" << i << " deep:" << dep[i] << " count:" << siz[i] << endl;
    return 0;
}