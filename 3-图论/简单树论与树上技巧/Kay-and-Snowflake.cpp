#include<iostream>
#include<vector>
using namespace std;

const int N = 3e5 + 5;
vector<int> G[N];
int siz[N],mxs[N],dep[N],ans[N],p[N];

void dfs(int u,int pa) {
    siz[u] = 1;
    for (auto v : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
        siz[u] += siz[v], mxs[u] = max(mxs[u],siz[v]);
    }
    int heavy = u,minn = mxs[u];
    // heavy 代表重心，minn 记录去除重心的最大连通块最小值
    for (auto v : G[u]) {
        int tmp = max(mxs[ans[v]],siz[u] - siz[ans[v]]),pos = ans[v],last = pos;
        while (p[pos] != u) {
            pos = p[pos];
            if (max(mxs[pos],siz[u] - siz[pos]) < tmp)
                tmp = max(mxs[pos],siz[u] - siz[pos]), last = pos;
            else break;
        }
        if (minn > tmp) minn = tmp,heavy = last;
    }
    ans[u] = heavy;
    return ;
}

int main() {
    int n,q;
    cin >> n >> q;
    for (int i = 2;i <= n;i++) {
        cin >> p[i];
        G[p[i]].push_back(i); G[i].push_back(p[i]);
    }
    dfs(1,0);
    while (q--) {
        int v;
        cin >> v;
        cout << ans[v] << endl;
    }
    return 0;
}