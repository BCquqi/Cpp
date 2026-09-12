#include<iostream>
#define int long long
#define lid id << 1
#define rid id << 1 | 1
using namespace std;

const int N = 1e6 + 5;
int a[N];
struct seg_tree {int l,r,lazy,maxn,assign;} tr[N << 2];

inline void pushup(int id) {
    tr[id].maxn = max(tr[lid].maxn,tr[rid].maxn);
    return ;
}

inline void addtag(int id,int val) {
    tr[id].lazy += val, tr[id].maxn += val;
    return ;
} 

inline void asstag(int id,int val) {
    tr[id].assign = val, tr[id].lazy = 0, tr[id].maxn = val;
    return ;
}

void pushdown(int id) {
    if (tr[id].assign != 1e18) {
        asstag(lid,tr[id].assign), asstag(rid,tr[id].assign);
        tr[id].assign = 1e18;
    }
    if (tr[id].lazy) {
        addtag(lid,tr[id].lazy), addtag(rid,tr[id].lazy);
        tr[id].lazy = 0;
    }
}

void build(int id,int l,int r) {
    tr[id].l = l,tr[id].r = r;
    tr[id].assign = 1e18;
    if (l == r) {
        tr[id].maxn = a[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(lid,l,mid);
    build(rid,mid + 1,r);
    pushup(id);
    return ;
}

void modify(int id,int l,int r,int val) {
    if (l <= tr[id].l && tr[id].r <= r) {
        asstag(id,val);
        return ;
    }
    pushdown(id);
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (r <= mid) modify(lid,l,r,val);
    else if (l > mid) modify(rid,l,r,val);
    else modify(lid,l,mid,val), modify(rid,mid + 1,r,val);
    pushup(id);
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
    if (tr[id].l == l && tr[id].r == r) return tr[id].maxn;
    pushdown(id);
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (r <= mid) return query(lid,l,r);
    else if (l > mid) return query(rid,l,r);
    else return max(query(lid,l,mid),query(rid,mid + 1,r));
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,q;
    cin >> n >> q;
    for (int i = 1;i <= n;i++) cin >> a[i];
    build(1,1,n);
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l,r,x;
            cin >> l >> r >> x;
            modify(1,l,r,x);
        } else if (op == 2) {
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