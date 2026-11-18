#include<iostream>
#include<algorithm>
#include<cstring>
#define lid id * 2
#define rid id * 2 + 1
// #define int long long
using namespace std;

const int N = 1e5 + 5;
int a[N];

struct seg_tree {int l,r,lazy,mx;} tr[N << 2];

void build(int id,int l,int r) {
    tr[id].l = l,tr[id].r = r;
    if (l == r) return ;
    int mid = (l + r) >> 1;
    build(lid,l,mid);
    build(rid,mid + 1,r);
}

void pushdown(int id) {
    if (tr[id].lazy && tr[id].l != tr[id].r) {
        tr[lid].lazy += tr[id].lazy;
        tr[rid].lazy += tr[id].lazy;
        tr[lid].mx += tr[id].lazy;
        tr[rid].mx += tr[id].lazy;
        tr[id].lazy = 0;
    }
}

void add(int id,int l,int r,int val) {
    if (l <= tr[id].l && tr[id].r <= r) {
        tr[id].lazy += val;
        tr[id].mx += val;
        return ;
    }
    pushdown(id);
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (r <= mid) add(lid,l,r,val);
    else if (l > mid) add(rid,l,r,val);
    else add(lid,l,mid,val), add(rid,mid + 1,r,val);
    tr[id].mx = max(tr[lid].mx,tr[rid].mx);
}

int query(int id,int l,int r) {
    pushdown(id);
    if (tr[id].l == l && tr[id].r == r) return tr[id].mx;
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (r <= mid) return query(lid,l,r);
    else if (l > mid) return query(rid,l,r);
    else return max(query(lid,l,mid),query(rid,mid + 1,r));
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    build(1,1,n);
    while (n--) {
        int op,k1,k2;
        cin >> op >> k1 >> k2;
        if (op == 1) add(1,k1,k2,1);
        else cout << query(1,k1,k2) << '\n';
    }
    return 0;
}