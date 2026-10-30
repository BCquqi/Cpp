#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long LL;

const int N = 3e5 + 5,M = 1 << 8,MM = 1 << 6;
int n,len,tot,top;
int a[N],ls[N],rs[N],siz[N],bid[N],stk[N];
int cnt[700][MM][M],f[700][MM][M],g[700][MM][M];
LL ans;
vector<int> vec[N];

inline void insert(int x,int idx) {
    int h = x >> 8,l = x & (M - 1);
    ++cnt[idx][h][l];
    for (int i = l;i < M;i = (i + 1) | l) ++f[idx][h][i];
    for (int i = l;i;i = (i - 1) & l) ++g[idx][h][i];
    ++g[idx][h][0];
    return ;
}

inline int query(int x,int idx) {
    int h = x >> 8,l = x & (M - 1),res = -cnt[idx][h][l];
    for (int i = h;i < MM;i = (i + 1) | h) res += g[idx][i][l];
    for (int i = h;i;i = (i - 1) & h) res += f[idx][i][l];
    res += f[idx][0][l];
    return res;
}

void solve(int u) {
    if (ls[u]) solve(ls[u]);
    if (rs[u]) solve(rs[u]);
    siz[u] = siz[ls[u]] + siz[rs[u]] + 1;
    if (!ls[u] && !rs[u]) {
        bid[u] = 0;
        vec[u].push_back(a[u]);
        return ;
    }
    if (!ls[u] || siz[rs[u]] > siz[ls[u]]) {
        swap(vec[u],vec[rs[u]]);
        bid[u] = bid[rs[u]];
        if (siz[u] >= len && !bid[u]) {
            bid[u] = ++tot;
            for (auto x : vec[u]) insert(x,bid[u]);
        }
        if (!bid[u]) {
            for (auto x : vec[ls[u]]) for (auto y : vec[u]) if ((x & y) == x || (x & y) == y) ans += a[u];
            for (auto x : vec[ls[u]]) vec[u].push_back(x);
            vec[ls[u]].clear();
            for (auto x : vec[u]) if ((x & a[u]) == x || (x & a[u]) == a[u]) ans += a[u];
            vec[u].push_back(a[u]);
        } else {
            for (auto x : vec[ls[u]]) ans += 1ll * query(x,bid[u]) * a[u];
            for (auto x : vec[ls[u]]) insert(x,bid[u]);
            vec[u].insert(vec[u].end(),vec[ls[u]].begin(),vec[ls[u]].end());
            vec[ls[u]].clear();
            ans += 1ll * query(a[u],bid[u]) * a[u];
            insert(a[u],bid[u]);
            vec[u].push_back(a[u]);
        }
    } else {
        swap(vec[u],vec[ls[u]]);
        bid[u] = bid[ls[u]];
        if (siz[u] >= len && !bid[u]) {
            bid[u] = ++tot;
            for (auto x : vec[u]) insert(x,bid[u]);
        }
        if (!bid[u]) {
            for (auto x : vec[rs[u]]) for (auto y : vec[u]) if ((x & y) == x || (x & y) == y) ans += a[u];
            for (auto x : vec[rs[u]]) vec[u].push_back(x);
            vec[rs[u]].clear();
            for (auto x : vec[u]) if ((x & a[u]) == x || (x & a[u]) == a[u]) ans += a[u];
            vec[u].push_back(a[u]);
        } else {
            for (auto x : vec[rs[u]]) ans += 1ll * query(x,bid[u]) * a[u];
            for (auto x : vec[rs[u]]) insert(x,bid[u]);
            vec[u].insert(vec[u].end(),vec[rs[u]].begin(),vec[rs[u]].end());
            vec[rs[u]].clear();
            ans += 1ll * query(a[u],bid[u]) * a[u];
            insert(a[u],bid[u]);
            vec[u].push_back(a[u]);
        }
    }
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("score.in","r",stdin);
    freopen("score.out","w",stdout);
    cin >> n;
    len = n / 700 + 1;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++) {
        while (top && a[stk[top]] < a[i]) ls[i] = stk[top--];
        if (top) rs[stk[top]] = i;
        stk[++top] = i;
    }
    solve(stk[1]);
    cout << ans << endl;
    return 0;
}