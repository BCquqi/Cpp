#include<iostream>
#include<algorithm>
#include<vector>
#define lid id << 1
#define rid id << 1 | 1
#define int long long
using namespace std;

const int N = 2e5 + 5;
struct Edge {int l,w;};
int a[N],g[N],tr[N << 2],lazy[N << 2],n,m;
vector<Edge> G[N];

void build(int id,int l,int r) {
    tr[id] = -1e18;
    if (l == r) return ;
    int mid = (l + r) >> 1;
    build(id << 1,l,mid);
    build(id << 1 | 1,mid + 1,r);
}

void pushdown(int id) {
    if (lazy[id]) {
        tr[lid] += lazy[id],lazy[lid] += lazy[id];
        tr[rid] += lazy[id],lazy[rid] += lazy[id];
        lazy[id] = 0;
    }
}

void add(int id,int l,int r,int ql,int qr,int val) {
    if (ql <= l && r <= qr) {
        tr[id] += val,lazy[id] += val;
        return ;
    }
    pushdown(id);
    int mid = (l + r) >> 1;
    if (ql <= mid) add(lid,l,mid,ql,qr,val);
    if (qr > mid) add(rid,mid + 1,r,ql,qr,val);
    tr[id] = max(tr[lid],tr[rid]);
}

void modify(int id,int l,int r,int pos,int val) {
    if (l == r) {
        tr[id] = val;
        return ;
    }
    pushdown(id);
    int mid = (l + r) >> 1;
    if (pos <= mid) modify(lid,l,mid,pos,val);
    else modify(rid,mid + 1,r,pos,val);
    tr[id] = max(tr[lid],tr[rid]);
}

int query(int id,int l,int r,int ql,int qr) {
    if (ql <= l && r <= qr) return tr[id];
    pushdown(id);
    int mid = (l + r) >> 1;
    if (qr <= mid) return query(lid,l,mid,ql,qr);
    else if (ql > mid) return query(rid,mid + 1,r,ql,qr);
    else return max(query(lid,l,mid,ql,mid),query(rid,mid + 1,r,mid + 1,qr));
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= m;i++) {
        int l,r,w;
        cin >> l >> r >> w;
        G[r].push_back({l,w});
    }
    build(1,0,n);
    modify(1,0,n,0,0);
    for (int i = 1;i <= n;i++) {
        add(1,0,n,0,i - 1,-a[i]);
        for (auto p : G[i]) add(1,0,n,0,p.l - 1,p.w);
        int fi = query(1,0,n,0,i - 1);
        g[i] = max(fi,g[i - 1]);
        modify(1,0,n,i,g[i - 1]);
    }
    cout << g[n] << endl;
    return 0;
}