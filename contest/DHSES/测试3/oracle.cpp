#include<iostream>
#include<algorithm>
#define lid id * 2
#define rid id * 2 + 1
using namespace std;

const int N = 2e5 + 5;
int a[N],mid[N],cur = 0;
struct Segment_Tree{int l,r,lazy;} tr[N << 2];

void build(int id,int l,int r) {
    tr[id].l = l, tr[id].r = r;
    // cout << l << ' ' << r << endl;
    if (l == r) {
        tr[id].lazy = a[l];
        return ;
    }
    int m = mid[++cur];
    build(lid,l,m);
    build(rid,m + 1,r);
    return ;
}

int query(int id,int l,int r) {
    // cout << "query: " << tr[id].l << ' ' << tr[id].r << endl;
    if (tr[id].l == l && tr[id].r == r) return tr[id].lazy;
    // 两侧一定只有一侧包含该节点
    if (tr[lid].l <= l && tr[lid].r >= r) return query(lid,l,r);
    else if (tr[rid].l <= l && tr[rid].r >= r) return query(rid,l,r);
}

void pushdown(int id) {
    // cout << "pushdown: [" << tr[id].l << ',' << tr[id].r << ']' << " to [" << tr[lid].l << ',' << tr[lid].r << ']' << " and [" << tr[rid].l << ',' << tr[rid].r << ']' << endl;
    tr[lid].lazy += tr[id].lazy, tr[rid].lazy += tr[id].lazy;
    tr[id].lazy = 0;
    return ;
}

void modify(int id,int l,int r,int k) {
    if (l <= tr[id].l && tr[id].r <= r) {
        tr[id].lazy += k;
        // cout << "add: " << tr[id].l << ' ' << tr[id].r << endl;
        return ;
    }
    pushdown(id);
    if (tr[lid].l <= l && tr[lid].r >= r) modify(lid,l,r,k);
    else if (tr[rid].l <= l && tr[rid].r >= r) modify(rid,l,r,k);
    else modify(lid,l,tr[lid].r,k), modify(rid,tr[rid].l,r,k);
    return ;
}

int main() {
    freopen("oracle.in","r",stdin);
    freopen("oracle.out","w",stdout);
    int n,q;
    cin >> n >> q;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i < n;i++) cin >> mid[i];
    build(1,1,n);
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l,r;
            cin >> l >> r;
            cout << query(1,l,r) << endl;
        } else {
            int l,r,k;
            cin >> l >> r >> k;
            modify(1,l,r,k);
        }
    }
    return 0;
}