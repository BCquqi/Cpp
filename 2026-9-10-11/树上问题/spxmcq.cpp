#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define int long long
using namespace std;

const int N = 1e6 + 5;
struct Query {int id,u,x;} q[N];
int f[N],a[N],fa[N],dfn[N],sz[N],ans[N],idx,c1[N],c2[N];
vector<int> G[N];

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

struct Node {
    int id,thr;
    bool operator < (const Node &x) const {return thr > x.thr;}
};
priority_queue<Node> pq;

int n,m;
int lowbit(int x) {return x & -x;}
void change1(int x,int t) {while (x <= n) c1[x] += t, x += lowbit(x);}
void change2(int x,int t) {while (x <= n) c2[x] += t, x += lowbit(x);}
int sum1(int x) {int ans = 0; while (x > 0) ans += c1[x], x -= lowbit(x); return ans;}
int sum2(int x) {int ans = 0; while (x > 0) ans += c2[x], x -= lowbit(x); return ans;}
int query1(int l,int r) {return sum1(r) - sum1(l - 1);}
int query2(int l,int r) {return sum2(r) - sum2(l - 1);}

int find(int x) {
    while (x != fa[x]) x = fa[x] = fa[fa[x]];
    return x;
}

inline int d(int x,int y) {
    if (x >= 0) return x / y + (x % y != 0);
    else return x / y;
}

void dfs(int x) {
    dfn[x] = ++idx; sz[x] = 1;
    for (auto v : G[x]) dfs(v),sz[x] += sz[v];
}

signed main() {
    n = read(), m = read();
    for (int i = 2;i <= n;i++) f[i] = read(), G[f[i]].push_back(i);
    for (int i = 1;i <= n;i++) a[i] = read();
    dfs(1);
    for (int i = 1;i <= n;i++) {
        fa[i] = i;
        change1(dfn[i],1), change2(dfn[i],a[i]);
        if (i != 1) change1(dfn[f[i]],-1), change2(dfn[f[i]],-a[i]);
    }
    for (int i = 2;i <= n;i++) {
        int s1 = query1(dfn[i],dfn[i] + sz[i] - 1);
        int s2 = query2(dfn[i],dfn[i] + sz[i] - 1);
        pq.push({i,d(-s2,s1)});
    }
    for (int i = 1;i <= m;i++) {
        q[i].u = read(), q[i].x = read();
        q[i].id = i;
    }
    sort(q + 1,q + m + 1,[](Query p,Query q) {return p.x < q.x;});
    for (int i = 1;i <= m;i++) {
        while (!pq.empty() && pq.top().thr <= q[i].x) {
            auto [id,thr] = pq.top(); pq.pop();
            if (find(id) != id) continue;
            int s1 = query1(dfn[id],dfn[id] + sz[id] - 1);
            int s2 = query2(dfn[id],dfn[id] + sz[id] - 1);
            if (d(-s2,s1) != thr) continue;
            while (id != 1) {
                int rt = find(f[id]);
                if (rt == 0) break;
                int tmp1 = query1(dfn[id],dfn[id] + sz[id] - 1);
                int tmp2 = query2(dfn[id],dfn[id] + sz[id] - 1);
                change1(dfn[f[id]],tmp1), change2(dfn[f[id]],tmp2);
                if (f[rt] != 0) change1(dfn[f[rt]],-tmp1), change2(dfn[f[rt]],-tmp2);
                fa[id] = rt;
                tmp1 = query1(dfn[rt],dfn[rt] + sz[rt] - 1);
                tmp2 = query2(dfn[rt],dfn[rt] + sz[rt] - 1);
                if (tmp2 + tmp1 * q[i].x < 0) {
                    pq.push({rt,d(-tmp2,tmp1)});
                    break;
                }
                else id = rt;
            }
        }
        ans[q[i].id] = query2(dfn[q[i].u],dfn[q[i].u] + sz[q[i].u] - 1) + query1(dfn[q[i].u],dfn[q[i].u] + sz[q[i].u] - 1) * q[i].x;
    }
    for (int i = 1;i <= m;i++) write(ans[i]);
    return 0;
}