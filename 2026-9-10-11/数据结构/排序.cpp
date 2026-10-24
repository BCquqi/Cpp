#include<iostream>
#define lid id << 1
#define rid id << 1 | 1
using namespace std;

const int N = 1e5 + 5;
struct Query {int op,l,r;} qq[N];
struct segment_tree {int l,r,len,sum,lazy;} tr[(N << 2) + 5];
// LazyTag: -1 -> no tag, 0 -> all to 0, 1 -> all to 1
int a[N],b[N];

inline void pushup(int id) {
    tr[id].sum = tr[lid].sum + tr[rid].sum;
    return ;
}

void build(int id,int l,int r) {
    tr[id].l = l, tr[id].r = r, tr[id].len = r - l + 1, tr[id].lazy = -1;
    if (l == r) {
        tr[id].sum = b[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(lid,l,mid), build(rid,mid + 1,r);
    pushup(id);
}

void pushdown(int id) {
    if (tr[id].lazy != -1 && tr[id].l != tr[id].r) {
        tr[lid].lazy = tr[rid].lazy = tr[id].lazy;
        tr[lid].sum = tr[lid].len * tr[id].lazy, 
        tr[rid].sum = tr[rid].len * tr[id].lazy;
        tr[id].lazy = -1;
    }
    return ;
}

void modify(int id,int l,int r,int val) {
    if (l <= tr[id].l && tr[id].r <= r) {
        tr[id].lazy = val, 
        tr[id].sum = tr[id].len * val;
        return ;
    }
    pushdown(id);
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (r <= mid) modify(lid,l,r,val);
    else if (l > mid) modify(rid,l,r,val);
    else modify(lid,l,mid,val), modify(rid,mid + 1,r,val);
    pushup(id);
}

int query(int id,int l,int r) {
    if (l <= tr[id].l && tr[id].r <= r) return tr[id].sum;
    pushdown(id);
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (r <= mid) return query(lid,l,r);
    else if (l > mid) return query(rid,l,r);
    else return query(lid,l,mid) + query(rid,mid + 1,r);
}

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= m;i++)
        cin >> qq[i].op >> qq[i].l >> qq[i].r;
    int q;
    cin >> q;
    if (!cin || q < 1 || q > n) return 0;
    int l = 1,r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        for (int i = 1;i <= n;i++)
            if (a[i] > mid) b[i] = 1;
            else b[i] = 0;
        build(1,1,n);
        for (int i = 1;i <= m;i++) {
            auto [op,ql,qr] = qq[i];
            int cnt1 = query(1,ql,qr), cnt0 = (qr - ql + 1) - cnt1;
            if (!cnt1 || !cnt0) continue;
            if (op == 0)
                modify(1,ql,ql + cnt0 - 1,0), modify(1,ql + cnt0,qr,1);
            else 
                modify(1,ql,ql + cnt1 - 1,1), modify(1,ql + cnt1,qr,0);
        }
        if (query(1,q,q) == 1) l = mid + 1;
        else r = mid;
    }
    cout << r << endl;
    return 0;
}