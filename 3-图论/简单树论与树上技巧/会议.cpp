#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 5e4 + 5;
vector<int> G[N];
int siz[N],mxs[N],dep[N];

void init(int u,int pa) {
    siz[u] = 1;
    for (auto v : G[u]) {
        if (v == pa) continue;
        init(v,u);
        siz[u] += siz[v], mxs[u] = max(mxs[u],siz[v]);
    }
    return ;
}

void dfs(int u,int pa) {
    dep[u] = dep[pa] + 1;
    for (auto v : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1;i < n;i++) {
        int a,b;
        cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    init(1,0);
    int point = 0,mnsiz = 1e9;
    for (int i = 1;i <= n;i++) {
        if (max(siz[1] - siz[i],mxs[i]) < mnsiz)
            mnsiz = max(siz[1] - siz[i],mxs[i]), point = i;
    }
    dep[0] = -1;
    dfs(point,0);
    long long ans = 0;
    for (int i = 1;i <= n;i++) ans += dep[i];
    cout << point << ' ' << ans << endl;
    return 0;
}