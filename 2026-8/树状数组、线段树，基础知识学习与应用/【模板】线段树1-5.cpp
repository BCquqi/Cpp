#include<iostream>
#define lid tr[id] -> lc
#define rid tr[id] -> rc
#define int unsigned long long
using namespace std;

const int N = 1e5 * 30 + 5;
int idx = 0;
struct seg_tree {
    int l,r,lc,rc;long long lazy,sum;
    seg_tree() : l(0),r(0),lc(0),rc(0),lazy(0),sum(0) {}
} *tr[N << 2];

int create(int l,int r) {
    tr[++idx] = new seg_tree();
    tr[idx] -> l = l, tr[idx] -> r = r;
    return idx;
}

void pushdown(int id) {
    if (!(tr[id] -> lazy) || tr[id] -> l == tr[id] -> r) return ;
    int mid = (tr[id] -> l + tr[id] -> r) >> 1;
    if (!lid) lid = create(tr[id] -> l,mid);
    if (!rid) rid = create(mid + 1,tr[id] -> r);
    tr[lid] -> lazy += tr[id] -> lazy;
    tr[lid] -> sum += tr[id] -> lazy * (tr[lid] -> r - tr[lid] -> l + 1);
    tr[rid] -> lazy += tr[id] -> lazy;
    tr[rid] -> sum += tr[id] -> lazy * (tr[rid] -> r - tr[rid] -> l + 1);
    tr[id] -> lazy = 0;
}

void modify(int id,int l,int r,int val) {
    if (l <= tr[id] -> l && tr[id] -> r <= r) {
        tr[id] -> lazy += val, 
        tr[id] -> sum += 1ll * val * (tr[id] -> r - tr[id] -> l + 1);
        return ;
    }
    pushdown(id);
    int mid = (tr[id] -> l + tr[id] -> r) >> 1;
    if (r <= mid) {
        if (!lid) lid = create(tr[id] -> l,mid);
        modify(lid,l,r,val);
    } else if (l > mid) {
        if (!rid) rid = create(mid + 1,tr[id] -> r);
        modify(rid,l,r,val);
    } else {
        if (!lid) lid = create(tr[id] -> l,mid);
        modify(lid,l,mid,val);
        if (!rid) rid = create(mid + 1,tr[id] -> r);
        modify(rid,mid + 1,r,val);
    }
    tr[id] -> sum = (lid ? tr[lid] -> sum : 0) + (rid ? tr[rid] -> sum : 0);
}

long long query(int id,int l,int r) {
    if (l <= tr[id] -> l && tr[id] -> r <= r) return tr[id] -> sum;
    pushdown(id);
    int mid = (tr[id] -> l + tr[id] -> r) >> 1;
    long long ret = 0;
    if (r <= mid) {
        if (!lid) return 0;
        ret = query(lid,l,r);
    } else if (l > mid) {
        if (!rid) return 0;
        ret = query(rid,l,r);
    } else {
        if (lid) ret += query(lid,l,mid);
        if (rid) ret += query(rid,mid + 1,r);
    }
    return ret;
}

signed main() {
    int n,m;
    cin >> n >> m;
    int rt = create(1,n);
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l,r,k;
            cin >> l >> r >> k;
            modify(rt,l,r,k);
        } else {
            int l,r;
            cin >> l >> r;
            cout << query(rt,l,r) + 1ll * (l + r) * (r - l + 1) / 2 << endl;
        }
    }
    return 0;
}