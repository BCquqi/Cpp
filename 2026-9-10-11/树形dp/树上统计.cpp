#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5 + 5;
vector<int> G[N];
int siz[N];

void dfs(int u,int pa) {
    siz[u] = 1;
    for (auto v : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
        maxn[u] = max(maxn[u],maxn[v]), 
        minn[u] = min(minn[u],minn[v]), 
        siz[u] += siz[v];
    }
    ans += (siz[u] == (maxn[u] - minn[u] + 1));
    return ;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        indeg[v]++;
    }
    int st = 0;
    for (int i = 1;i <= n;i++) if (indeg[i] == 0) {st = i; continue;}
    dfs(st,0);
    cout << ans << endl;
    return 0;
}