#include<iostream>
#define lid id << 1
#define rid id << 1 | 1
using namespace std;

const int N = 5e5 + 5;
int a[N];
struct seg_tree {int l,r,sum,mn,mx;} tr[N << 2];
struct answer {int sum,mn,mx;};

void pushup(int id) {
    tr[id].sum = tr[lid].sum + tr[rid].sum, 
    tr[id].mx = max(tr[lid].mx,tr[rid].mx), 
    tr[id].mn = min(tr[lid].mn,tr[rid].mn);
    return ;
}

void build(int id,int l,int r) {
    tr[id].l = l, tr[id].r = r;
    if (l == r) {
        tr[id].sum = tr[id].mx = tr[id].mn = a[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(lid,l,mid);
    build(rid,mid + 1,r);
    pushup(id);
    return ;
}

void modify(int id,int k,int val) {
    if (tr[id].l == k && tr[id].r == k) {
        tr[id].sum = tr[id].mx = tr[id].mn = val;
        return ;
    }
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (k <= mid) modify(lid,k,val);
    else modify(rid,k,val);
    pushup(id);
    return ;
}

answer query(int id,int l,int r) {
    if (tr[id].l == l && tr[id].r == r) return {tr[id].sum,tr[id].mn,tr[id].mx};
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (r <= mid) return query(lid,l,r);
    else if (l > mid) return query(rid,l,r);
    else {
        auto x = query(lid,l,mid),y = query(rid,mid + 1,r);
        return {x.sum + y.sum,min(x.mn,y.mn),max(x.mx,y.mx)};
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    build(1,1,n);
    while (m--) {
        char op;
        cin >> op;
        if (op == 'C') {
            int k,x;
            cin >> k >> x;
            modify(1,k,x);
        } else {
            int l,r;
            cin >> l >> r;
            auto ans = query(1,l,r);
            cout << ans.sum << ' ' << ans.mn << ' ' << ans.mx << endl;
        }
    }
    return 0;
}