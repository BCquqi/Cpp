#include<iostream>
#include<algorithm>
#define lid id * 2
#define rid id * 2 + 1
#define int long long
using namespace std;

const int N = 1e5 + 5;
int a[N];

struct seg_tree {int l,r,mx;} tr[N << 2];

void build(int id,int l,int r) {
    tr[id].l = l,tr[id].r = r;
    if (l == r) return ;
    int mid = (l + r) >> 1;
    build(lid,l,mid);
    build(rid,mid + 1,r);
}

void modify(int id,int k1,int k2) {
    if (tr[id].l == tr[id].r) {
        tr[id].mx = k2;
        return ;
    }
    int mid = (tr[id].l + tr[id].r) >> 1;
    modify(k1 <= mid ? lid : rid,k1,k2);
    tr[id].mx = max(tr[lid].mx,tr[rid].mx);
}

int query(int id,int l,int r) {
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
        if (op == 1) modify(1,k1,k2);
        else cout << query(1,k1,k2) << '\n';
    }
    return 0;
}