#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
#define lid id << 1
#define rid id << 1 | 1
using namespace std;

const int N = 1e6 + 5;
int v[N],dep[N],fa[N],siz[N],son[N],top[N],dfn[N],rnk[N],idx = 0;
vector<int> G[N];

struct seg_tree {int l,r,lazy,sum;} tr[N << 2];

void build(int id,int l,int r) {
    tr[id].l = l,tr[id].r = r;
    if (l == r) {
        tr[id].sum = v[rnk[l]];
        return ;
    }
    int mid = (l + r) >> 1;
    build(lid,l,mid);
    build(rid,mid + 1,r);
    tr[id].sum = tr[lid].sum + tr[rid].sum;
}

void pushdown(int id) {
    if (tr[id].lazy && tr[id].l != tr[id].r) {
        tr[lid].lazy += tr[id].lazy;
        tr[rid].lazy += tr[id].lazy;
        tr[lid].sum += tr[id].lazy * (tr[lid].r - tr[lid].l + 1);
        tr[rid].sum += tr[id].lazy * (tr[rid].r - tr[rid].l + 1);
        tr[id].lazy = 0;
    }
}

void modify(int id,int l,int r,int val) {
    if (l <= tr[id].l && tr[id].r <= r) {
        tr[id].lazy += val;
        tr[id].sum += val * (tr[id].r - tr[id].l + 1);
        return ;
    }
    pushdown(id);
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (r <= mid) modify(lid,l,r,val);
    else if (l > mid) modify(rid,l,r,val);
    else modify(lid,l,mid,val), modify(rid,mid + 1,r,val);
    tr[id].sum = tr[lid].sum + tr[rid].sum;
}

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
}

void dfs1(int u,int pa) {
    dep[u] = dep[pa] + 1, fa[u] = pa, siz[u] = 1, son[u] = 0;
    int maxn = 0;
    for (auto v : G[u]) {
        if (v == pa) continue;
        dep[v] = dep[u] + 1;
        dfs1(v,u);
        siz[u] += siz[v];
        if (siz[v] > maxn)
            maxn = siz[v], son[u] = v;
    }
}

void dfs2(int u,int t) {
    top[u] = t, dfn[u] = ++idx, rnk[dfn[u]] = u;
    if (son[u]) dfs2(son[u],t);
    for (auto v : G[u])
        if (v != fa[u] && v != son[u]) dfs2(v,v);
}

int query(int id,int l,int r) {
    if (l <= tr[id].l && tr[id].r <= r) return tr[id].sum;
    pushdown(id);
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (r <= mid) return query(lid,l,r);
    else if (l > mid) return query(rid,l,r);
    else return query(lid,l,mid) + query(rid,mid + 1,r);
}

void upd(int u,int v,int val) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u,v);
        modify(1,dfn[top[u]],dfn[u],val);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v]) swap(u,v);
    modify(1,dfn[v],dfn[u],val);
}

signed main() {
    int n = read(),m = read(),r = read();
    for (int i = 1;i <= n;i++) v[i] = read();
    for (int i = 1;i < n;i++) {
        int x = read(),y = read();
        G[x].push_back(y), G[y].push_back(x);
    }
    dep[r] = 1;
    dfs1(r,0);
    dfs2(r,r);
    build(1,1,n);
    while (m--) {
        int op = read();
        switch (op)
        {
            case 1 : {
                int a = read(),b = read(),x = read();
                upd(a,b,x);
                break;
            }
            case 2 : {
                int a = read();
                cout << query(1,dfn[a],dfn[a]) << endl;
                break;
            }
            case 3 : {
                int a = read();
                cout << query(1,dfn[a],dfn[a] + siz[a] - 1) << endl;
                break;
            }
        }
    }
    return 0;
}