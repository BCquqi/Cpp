#include<iostream>
#define int long long
#define lid id << 1
#define rid id << 1 | 1
using namespace std;

const int N = 1e5 + 5;
int a[N];
struct seg_tree {int l,r,lazy,sum;} tr[N << 2];

inline void pushup(int id) {
    tr[id].sum = tr[lid].sum + tr[rid].sum;
    return ;
}

inline void addtag(int id,int val) {
    tr[id].lazy += val, tr[id].sum += (tr[id].r - tr[id].l + 1) * val;
    return ;
}

void build(int id,int l,int r) {
    tr[id].l = l,tr[id].r = r;
    if (l == r) {
        tr[id].sum = a[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(lid,l,mid);
    build(rid,mid + 1,r);
    pushup(id);
    return ;
}

void pushdown(int id) {
    if (tr[id].lazy && tr[id].l != tr[id].r) {
        addtag(lid,tr[id].lazy), addtag(rid,tr[id].lazy);
        tr[id].lazy = 0;
    }
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
}

int query(int id,int l,int r) {
    if (tr[id].l == l && tr[id].r == r) return tr[id].sum;
    pushdown(id);
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (r <= mid) return query(lid,l,r);
    else if (l > mid) return query(rid,l,r);
    else return query(lid,l,mid) + query(rid,mid + 1,r);
}

signed main() {
    int n,q;
    cin >> n >> q;
    for (int i = 1;i <= n;i++) cin >> a[i];
    build(1,1,n);
    while (q--) {
        char op;
        cin >> op;
        if (op == 'C') {
            int l,r,x;
            cin >> l >> r >> x;
            add(1,l,r,x);
        } else {
            int l,r;
            cin >> l >> r;
            cout << query(1,l,r) << endl;
        }
    }
    return 0;
}