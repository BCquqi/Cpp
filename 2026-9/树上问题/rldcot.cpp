#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#define int long long
using namespace std;

const int N = 1e5 + 5;
struct Edge {int v,w;};
vector<Edge> G[N];
int n,m;
int siz[N],son[N],dfn[N],rev[N],idx = 0;
int euler[N << 1],first[N],eidx = 0;
int ans[N],last[N],tr[N],dis[N],dep[N],pos[N];
int st[N << 1][20],lg[N << 1];
struct Node {int l,r,id;};
vector<Node> a;
struct Query {int l,r,id;};
vector<Query> q;
vector<int> val;
set<int> s;

namespace FastIO {
    static const int BUF_SIZE = 1 << 20;
    static char buf[BUF_SIZE];
    static int p1 = 0, p2 = 0;

    static inline char nc() {
        if (p1 == p2) {
            p2 = (int)fread(buf, 1, BUF_SIZE, stdin);
            p1 = 0;
            if (p2 == 0) return EOF;
        }
        return buf[p1++];
    }

    static inline int read() {
        int x = 0, f = 1;
        int ch = nc();
        while (ch != EOF && (ch < '0' || ch > '9')) {
            if (ch == '-') f = -1;
            ch = nc();
        }
        while (ch != EOF && ch >= '0' && ch <= '9') {
            x = x * 10 + ch - '0';
            ch = nc();
        }
        return x * f;
    }

    static inline void write(int x) {
        static char out[32];
        int len = 0;
        if (x < 0) {
            putchar('-');
            x = -x;
        }
        do {
            out[len++] = static_cast<char>(x % 10 + '0');
            x /= 10;
        } while (x > 0);
        while (len--) putchar(out[len]);
        putchar('\n');
    }
}

using FastIO::read;
using FastIO::write;

inline int lowbit(int x) {return x & -x;}
inline void update(int x,int v) {for (int i = x;i <= n;i += lowbit(i)) tr[i] += v;}
inline int query(int x) {int res = 0;for (int i = x;i > 0;i -= lowbit(i)) res += tr[i]; return res;}

void dfs(int u,int pa) {
    siz[u] = 1, dfn[u] = ++idx, rev[idx] = u;
    int maxn = 0;
    first[u] = ++eidx, euler[eidx] = u;
    for (auto [v,w] : G[u]) {
        if (v == pa) continue;
        dis[v] = dis[u] + w, dep[v] = dep[u] + 1;
        dfs(v, u);
        siz[u] += siz[v];
        if (siz[v] > maxn) maxn = siz[v], son[u] = v;
        euler[++eidx] = u;
    }
}

inline int cmp(int x,int y) {return dep[x] < dep[y] ? x : y;}

void init() {
    lg[0] = -1;
    for (int i = 1;i <= eidx;i++) lg[i] = lg[i >> 1] + 1, st[i][0] = euler[i];
    for (int j = 1;j <= lg[eidx];j++)
        for (int i = 1;i + (1 << j) - 1 <= eidx;i++)
            st[i][j] = cmp(st[i][j - 1],st[i + (1 << (j - 1))][j - 1]);
}

int lca(int u,int v) {
    int l = first[u], r = first[v];
    if (l > r) swap(l, r);
    int k = lg[r - l + 1];
    return cmp(st[l][k],st[r - (1 << k) + 1][k]);
}

void add(int x,int u) {
    auto it = s.lower_bound(x);
    if (it != s.end()) {
        int y = *it;
        if (lca(x,y) == u) a.push_back({x,y,pos[u]});
    }
    if (it != s.begin()) {
        int y = *prev(it);
        if (lca(y,x) == u) a.push_back({y,x,pos[u]});
    }
    s.insert(x);
}

void dfs2(int u,int pa,bool keep) {
    for (auto [v,w] : G[u]) {
        if (v == pa || v == son[u]) continue;
        dfs2(v,u,false);
    }
    if (son[u]) dfs2(son[u],u,true);
    for (auto [v,w] : G[u]) {
        if (v == pa || v == son[u]) continue;
        for (int i = dfn[v];i < dfn[v] + siz[v];i++) add(rev[i],u);
    }
    add(u,u);
    if (!keep) s.clear();
}

signed main() {
    n = read(), m = read();
    for (int i = 1;i < n;i++) {
        int u,v,d;
        u = read(), v = read(), d = read();
        G[u].push_back({v,d}), G[v].push_back({u,d});
    }
    dfs(1,0);
    for (int i = 1;i <= n;i++) val.push_back(dis[i]);
    sort(val.begin(),val.end());
    val.erase(unique(val.begin(),val.end()),val.end());
    for (int i = 1;i <= n;i++)
        pos[i] = lower_bound(val.begin(),val.end(),dis[i]) - val.begin() + 1;
    init();
    dfs2(1,0,true);
    for (int i = 1;i <= n;i++) a.push_back({i,i,pos[i]});
    sort(a.begin(),a.end(),[](Node x,Node y) {return x.l != y.l ? x.l < y.l : x.r != y.r ? x.r < y.r : x.id < y.id;});
    a.erase(unique(a.begin(),a.end(),[](Node x,Node y) {return x.l == y.l && x.r == y.r && x.id == y.id;}),a.end());
    for (int i = 1;i <= m;i++) {
        int l,r;
        l = read(), r = read();
        q.push_back({l,r,i});
    }
    sort(a.begin(),a.end(),[](Node x,Node y) {return x.r < y.r;});
    sort(q.begin(),q.end(),[](Query x,Query y) {return x.r < y.r;});
    int cur = 0;
    for (auto [l,r,id] : q) {
        while (cur < a.size() && a[cur].r <= r) {
            int l = a[cur].l,id = a[cur].id;
            if (l > last[id]) {
                if (last[id]) update(last[id], -1);
                update(l, 1), last[id] = l;
            }
            cur++;
        }
        ans[id] = query(n) - query(l - 1);
    }
    for (int i = 1;i <= m;i++) write(ans[i]);
    return 0;
}