#include<iostream>
#include<algorithm>
#define lid 2 * id
#define rid 2 * id + 1
#define int long long
using namespace std;

const int N = 5e5 + 5;
int a[N],cpy[N];

struct seg_tree {int l,r,lazy,sum;} tr[N << 2];

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
        tr[lid].sum += tr[id].lazy * (tr[lid].r - tr[lid].l + 1);
        tr[rid].sum += tr[id].lazy * (tr[rid].r - tr[rid].l + 1);
        tr[id].lazy = 0;
    }
}

void add(int id,int l,int r,int val) {
    if (l <= tr[id].l && tr[id].r <= r) {
        tr[id].lazy += val;
        tr[id].sum += val * (tr[id].r - tr[id].l + 1);
        return ;
    }
    pushdown(id);
    int mid = (tr[id].l + tr[id].r) >> 1ll;
    if (r <= mid) add(lid,l,r,val);
    else if (l > mid) add(rid,l,r,val);
    else add(lid,l,mid,val), add(rid,mid + 1,r,val);
    tr[id].sum = tr[lid].sum + tr[rid].sum;
}

int query(int id,int l,int r) {
    pushdown(id);
    if (tr[id].l == l && tr[id].r == r) return tr[id].sum;
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (r <= mid) return query(lid,l,r);
    else if (l > mid) return query(rid,l,r);
    else return query(lid,l,mid) + query(rid,mid + 1,r);
}

signed main() {
    int n,ans = 0;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        cpy[i] = a[i];
    }
    build(1,1,n);
    sort(cpy + 1,cpy + n + 1);
    int len = unique(cpy + 1,cpy + n + 1) - cpy;
    for (int i = 1;i <= n;i++) {
        a[i] = lower_bound(cpy + 1,cpy + len + 1,a[i]) - cpy;
        add(1,a[i],a[i],1);
        ans += i - query(1,1,a[i]);
    }
    cout << ans << endl;
    return 0;
}