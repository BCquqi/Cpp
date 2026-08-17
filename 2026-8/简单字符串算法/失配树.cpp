#include<iostream>
#include<vector>
using namespace std;

const int N = 2e6 + 5;
int prefix[N],ans[N],cur = 0,dep[N],fa[N][32];
vector<int> G[N];

void init(string s) {
    int len = s.size();
    for (int i = 1;i < len;i++) {
        int j = prefix[i - 1];
        while (j > 0 && s[i] != s[j]) j = prefix[j - 1];
        if (s[i] == s[j]) j++;
        prefix[i] = j;
    }
    return ;
}

void build(string s) {
    init(s);
    for (int i = 1;i <= s.size();i++) {
        G[prefix[i - 1]].push_back(i);
        G[i].push_back(prefix[i - 1]);
    }
}

void dfs(int u,int pa) {
    dep[u] = dep[pa] + 1;
    fa[u][0] = pa;
    for (int i = 1;i <= 30;i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (auto v : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
    }
}

int LCA(int u,int v) {
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
    string s;
    cin >> s;
    build(s);
    dfs(0,0);
    int m;
    cin >> m;
    while (m--) {
        int p,q;
        cin >> p >> q;
        int lca = LCA(p,q);
        if (lca == p || lca == q) lca = fa[lca][0];
        cout << lca << endl;
    }
    return 0;
}