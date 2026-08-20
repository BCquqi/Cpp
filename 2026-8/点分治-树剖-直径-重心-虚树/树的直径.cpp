#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int N = 1e5 + 5;
vector<int> G[N];
int dep[N];

void dfs(int u,int pa) {
    dep[u] = dep[pa] + 1;
    for (auto v : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
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
    int s,mxdep = 0;
    for (int i = 1;i <= n;i++)
        if (mxdep < dep[i]) mxdep = dep[i], s = i;
    memset(dep,0,sizeof dep);
    dfs(s,0);
    mxdep = 0;
    for (int i = 1;i <= n;i++)
        if (mxdep < dep[i]) mxdep = dep[i];
    cout << mxdep - 1 << endl;
    return 0;
}