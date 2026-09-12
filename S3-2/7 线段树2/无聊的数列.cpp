#include<iostream>
#define int long long
#define lid id << 1
#define rid id << 1 | 1
using namespace std;

const int N = 1e5 + 5;
int a[N],d[N];
struct seg_tree {int l,r,lazy,sum;} tr[N << 2];

inline void pushup(int id) {
    tr[id].sum = tr[lid].sum + tr[rid].sum;
    return ;
}

inline void addtag(int id,int val) {
    tr[id].lazy += val, tr[id].sum += (tr[id].r - tr[id].l + 1) * val;
    return ;
}

inline void pushdown(int id) {
    if (tr[id].lazy && tr[id].l != tr[id].r) {
        addtag(lid,tr[id].lazy), addtag(rid,tr[id].lazy);
        tr[id].lazy = 0;
    }
}

void build(int id,int l,int r) {
    tr[id].l = l,tr[id].r = r;
    if (l == r) {
        tr[id].sum = d[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(lid,l,mid);
    build(rid,mid + 1,r);
    pushup(id);
    return ;
}

void add(int id,int l,int r,int val) {
    if (l <= tr[id].l && tr[id].r <= r) {
        addtag(id,val);
        return ;
    }
    pushdown(id);
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (r <= mid) add(lid,l,r,val);
    else if (l > mid) add(rid,l,r,val);
    else add(lid,l,mid,val), add(rid,mid + 1,r,val);
    pushup(id);
    return ;
}

int query(int id,int l,int r) {
    if (l <= tr[id].l && tr[id].r <= r) return tr[id].sum;
    pushdown(id);
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (r <= mid) return query(lid,l,r);
    else if (l > mid) return query(rid,l,r);
    else return query(lid,l,mid) + query(rid,mid + 1,r);
}

signed main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        d[i] = a[i] - a[i - 1];
    }
    build(1,1,n);
    while (m--) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int l,r,k,d;
            cin >> l >> r >> k >> d;
            add(1,l,l,k);
            if (l < r) add(1,l + 1,r,d);
            if (r < n) add(1,r + 1,r + 1,-k - (r - l) * d);
        } else {
            int p;
            cin >> p;
            cout << query(1,1,p) << endl;
        }
    }
    return 0;
}