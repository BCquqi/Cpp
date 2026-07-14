#include<iostream>
#include<algorithm>
#include<cstring>
#define lid id * 2
#define rid id * 2 + 1
#define int long long
using namespace std;

const int N = 1e5 + 5;
int a[N],n,p;

struct seg_tree {int l,r,lazy,sum,lzym;} tr[N << 2];

void build(int id,int l,int r) {
    tr[id].l = l,tr[id].r = r,tr[id].lzym = 1;
    if (l == r) {
        tr[id].sum = a[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(lid,l,mid);
    build(rid,mid + 1,r);
    tr[id].sum = (tr[lid].sum + tr[rid].sum) % p;
}

void pushdown(int id) {
    if ((tr[id].lazy || tr[id].lzym != 1) && tr[id].l != tr[id].r) {
        tr[lid].lzym *= tr[id].lzym;
        tr[rid].lzym *= tr[id].lzym;
        tr[lid].sum *= tr[id].lzym;
        tr[rid].sum *= tr[id].lzym;
        tr[lid].lazy *= tr[id].lzym;
        tr[rid].lazy *= tr[id].lzym;

        tr[lid].lzym %= p,tr[rid].lzym %= p,tr[lid].sum %= p,tr[rid].sum %= p,tr[lid].lazy %= p,tr[rid].lazy %= p;

        tr[lid].lazy += tr[id].lazy;
        tr[rid].lazy += tr[id].lazy;
        tr[lid].sum += tr[id].lazy * (tr[lid].r - tr[lid].l + 1);
        tr[rid].sum += tr[id].lazy * (tr[rid].r - tr[rid].l + 1);

        tr[lid].lazy %= p,tr[rid].lazy %= p,tr[lid].sum %= p,tr[rid].sum %= p;

        tr[id].lazy = 0,tr[id].lzym = 1;
    }
}

void add(int id,int l,int r,int val) {
    if (l <= tr[id].l && tr[id].r <= r) {
        tr[id].lazy += val;
        tr[id].sum += val * (tr[id].r - tr[id].l + 1);
        tr[id].lazy %= p,tr[id].sum %= p;
        return ;
    }
    pushdown(id);
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (r <= mid) add(lid,l,r,val);
    else if (l > mid) add(rid,l,r,val);
    else add(lid,l,mid,val), add(rid,mid + 1,r,val);
    tr[id].sum = (tr[lid].sum + tr[rid].sum) % p;
}

void mul(int id,int l,int r,int val) {
    if (l <= tr[id].l && tr[id].r <= r) {
        tr[id].lzym *= val;
        tr[id].sum *= val;
        tr[id].lazy *= val; // 这里加法lazy也要加倍以正确下传
        tr[id].lzym %= p,tr[id].sum %= p,tr[id].lazy %= p;
        return ;
    }
    pushdown(id);
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (r <= mid) mul(lid,l,r,val);
    else if (l > mid) mul(rid,l,r,val);
    else mul(lid,l,mid,val), mul(rid,mid + 1,r,val);
    tr[id].sum = (tr[lid].sum + tr[rid].sum) % p;
}

int query(int id,int l,int r) {
    pushdown(id);
    if (tr[id].l == l && tr[id].r == r) return tr[id].sum % p;
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (r <= mid) return query(lid,l,r);
    else if (l > mid) return query(rid,l,r);
    else return (query(lid,l,mid) + query(rid,mid + 1,r)) % p;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> p;
    for (int i = 1;i <= n;i++) cin >> a[i];
    build(1,1,n);
    int m;
    cin >> m;
    while (m--) {
        int op;
        cin >> op;
        switch (op) {
            case 1 : {
                int t,g,c;
                cin >> t >> g >> c;
                mul(1,t,g,c);
                break;
            }
            case 2 : {
                int t,g,c;
                cin >> t >> g >> c;
                add(1,t,g,c);
                break;
            }
            case 3 : {
                int t,g;
                cin >> t >> g;
                cout << query(1,t,g) << '\n';
                break;
            }
        }
    }
    return 0;
}