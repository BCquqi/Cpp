#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

const int N = 1e5 + 5;
struct Node {int p,dfn;} s[N];
vector<int> G[N];
set<int> st;
int id = 0,dep[N],fa[N][32],re[N];

void dfs(int u,int pa) {
    s[u].dfn = ++id, re[id] = u; // 建立双向映射
    dep[u] = dep[pa] + 1;
    fa[u][0] = pa;
    for (int i = 1;i <= 30;i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (auto v : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
    }
}

int lca(int u,int v) {
    if (dep[u] < dep[v]) swap(u,v);
    for (int i = 30;i >= 0;i--)
        if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
    if (u == v) return v;
    for (int i = 30;i >= 0;i--)
        if (fa[u][i] != fa[v][i])
            u = fa[u][i],v = fa[v][i];
    return fa[u][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 2;i <= n;i++) {
        cin >> s[i].p;
        G[s[i].p].push_back(i); G[i].push_back(s[i].p);
    }
    dep[0] = -1;
    dfs(1,0);
    int ans = 0;
    while (m--) {
        int op;
        cin >> op;
        switch (op) {
            case 1 : {
                int u;
                cin >> u;
                auto it = st.insert(s[u].dfn).first;
                int pre = (it == st.begin()) ? -1 : *prev(it);
                int nxt = (next(it) == st.end()) ? -1 : *next(it);
                if (pre != -1 && nxt != -1) ans += dep[lca(re[pre],re[nxt])];
                if (pre != -1) ans -= dep[lca(re[pre],u)];
                if (nxt != -1) ans -= dep[lca(re[nxt],u)];
                ans += dep[u];
                break;
            }
            case 2 : {
                int u;
                cin >> u;
                auto it = st.find(s[u].dfn);
                int pre = (it == st.begin()) ? -1 : *prev(it);
                int nxt = (next(it) == st.end()) ? -1 : *next(it);
                if (pre != -1 && nxt != -1) ans -= dep[lca(re[pre],re[nxt])];
                if (pre != -1) ans += dep[lca(re[pre],u)];
                if (nxt != -1) ans += dep[lca(re[nxt],u)];
                ans -= dep[u];
                st.erase(s[u].dfn);
                break;
            }
            case 3 : {
                cout << ans << '\n';
                break;
            }
        }
    }
    return 0;
}