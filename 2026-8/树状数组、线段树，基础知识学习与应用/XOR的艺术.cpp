#include<iostream>
#define lid id * 2
#define rid id * 2 + 1
using namespace std;

const int N = 2e5 + 5;
int a[N];

struct seg_tree {int l,r,lazy,val;} tr[N << 2];

void build(int id,int l,int r) {
    tr[id].l = l,tr[id].r = r;
    if (l == r) {
        tr[id].val = a[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(lid,l,mid);
    build(rid,mid + 1,r);
    tr[id].val = tr[lid].val + tr[rid].val;
}

void pushdown(int id) {
    if (!tr[id].lazy) return ;
    tr[lid].val = tr[lid].r - tr[lid].l + 1 - tr[lid].val;
    tr[rid].val = tr[rid].r - tr[rid].l + 1 - tr[rid].val;
    tr[lid].lazy ^= 1, tr[rid].lazy ^= 1, tr[id].lazy = 0;
    return ;
}

void modify(int id,int l,int r) {
    if (l <= tr[id].l && tr[id].r <= r) {
        tr[id].lazy ^= 1;
        tr[id].val = tr[id].r - tr[id].l + 1 - tr[id].val;
        return ;
    }
    pushdown(id);
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (r <= mid) modify(lid,l,r);
	else if (l > mid) modify(rid,l,r);
	else modify(lid,l,mid), modify(rid,mid + 1,r);
    tr[id].val = tr[lid].val + tr[rid].val;
}

int query(int id,int l,int r) {
    if (tr[id].l == l && tr[id].r == r) return tr[id].val;
    pushdown(id);
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (r <= mid) return query(lid,l,r);
	else if (l > mid) return query(rid,l,r);
	else return query(lid,l,mid) + query(rid,mid + 1,r);
}

int main() {
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 0;i < n;i++) a[i + 1] = s[i] - '0';
    build(1,1,n);
    while (m--) {
        int op,l,r;
        cin >> op >> l >> r;
        if (op == 0) modify(1,l,r);
        else cout << query(1,l,r) << endl;
    }
    return 0;
}