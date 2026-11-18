#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int N = 1e5 + 5;
vector<int> G[N];
int siz[N],mxs[N],heavy[5],lf,fa;

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
    if (pa != 0 && G[u].size() == 1) {
        lf = u, fa = pa;
        return ;
    }
    for (auto v : G[u]) {
        if (v == pa || v == heavy[2]) continue; // 不可以是 heavy2 和 heavy1 的共同儿子
        dfs(v,u);
        if (lf) return ;
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) G[i].clear();
    memset(siz,0,sizeof siz); memset(mxs,0,sizeof mxs);
    lf = fa = 0, heavy[0] = heavy[1] = 0;
    for (int i = 1;i < n;i++) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y); G[y].push_back(x);
    }
    init(1,0);
    int point = 0,mnsiz = 1e9;
    for (int i = 1;i <= n;i++) {
        if (max(siz[1] - siz[i],mxs[i]) < mnsiz)
            mnsiz = max(siz[1] - siz[i],mxs[i]), point = i;
    }
    int cnt = 0;
    for (int i = 1;i <= n;i++)
        if (max(siz[1] - siz[i],mxs[i]) == mnsiz) heavy[++cnt] = i;
    if (cnt == 1) cout << "1 " << G[1][0] << "\n1 " << G[1][0] << "\n";
    else {
        dfs(heavy[1],0); // 找到 heavy1 的一个叶子节点
        cout << fa << ' ' << lf << endl;
        cout << heavy[2] << ' ' << lf << endl;
    }
    return ;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}