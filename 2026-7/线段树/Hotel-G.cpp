#include<iostream>
#define lid id * 2
#define rid id * 2 + 1
#define int long long
using namespace std;

const int N = 1e5 + 5;
int a[N];

struct seg_tree {int l,r,sum,lmax,rmax,lazy;} tr[N << 2];
// sum 是区间最大连续空房数，lrmax 表示从左 / 右开始的最大连续空房数

void build(int id,int l,int r) {
    tr[id].l = l,tr[id].r = r;
    tr[id].sum = tr[id].lmax = tr[id].rmax = r - l + 1;
    if (l == r) return ;
    int mid = (l + r) >> 1;
    build(lid,l,mid);
    build(rid,mid + 1,r);
}

void pushdown(int id) {
    if (tr[id].lazy && tr[id].l != tr[id].r) {
        if (tr[id].lazy == 1) {
            tr[lid].lazy = tr[rid].lazy = 1;
            tr[lid].sum = tr[lid].lmax = tr[lid].rmax = 0;
            tr[rid].sum = tr[rid].lmax = tr[rid].rmax = 0;
        }
        else if (tr[id].lazy == 2) {
            tr[lid].lazy = tr[rid].lazy = 2;
            tr[lid].sum = tr[lid].lmax = tr[lid].rmax = tr[lid].r - tr[lid].l + 1;
            tr[rid].sum = tr[rid].lmax = tr[rid].rmax = tr[rid].r - tr[rid].l + 1;
        }
        tr[id].lazy = 0;
    }
}

void pushup(int id) {
    if (tr[lid].sum == tr[lid].r - tr[lid].l + 1) // 左边都是空
        tr[id].lmax = tr[lid].r - tr[lid].l + 1 + tr[rid].lmax;
    else tr[id].lmax = tr[lid].lmax;
    if (tr[rid].sum == tr[rid].r - tr[rid].l + 1) // 右边都是空
        tr[id].rmax = tr[rid].r - tr[rid].l + 1 + tr[lid].rmax;
    else tr[id].rmax = tr[rid].rmax;
    tr[id].sum = max(max(tr[lid].sum,tr[rid].sum),tr[lid].rmax + tr[rid].lmax); // 全左，全右，左右都有
}

void add(int id,int l,int r,int flag) {
    if (l <= tr[id].l && tr[id].r <= r) {
        if (flag == 1) tr[id].sum = tr[id].lmax = tr[id].rmax = 0;
        else if (flag == 2) tr[id].sum = tr[id].lmax = tr[id].rmax = tr[id].r - tr[id].l + 1;
        tr[id].lazy = flag;
        return ;
    }
    pushdown(id);
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (r <= mid) add(lid,l,r,flag);
    else if (l > mid) add(rid,l,r,flag);
    else add(lid,l,mid,flag), add(rid,mid + 1,r,flag);
    pushup(id);
}

int query(int id,int l,int r,int len) {
    if (l == r) return l;
    pushdown(id);
    int mid = (l + r) >> 1;
    if (tr[lid].sum >= len) return query(lid,l,mid,len);
    else if (tr[lid].rmax + tr[rid].lmax >= len) return mid - tr[lid].rmax + 1;
    else return query(rid,mid + 1,r,len);
}

signed main() {
    int n,m;
    cin >> n >> m;
    build(1,1,n);
    while (m--) {
        int i;
        cin >> i;
        if (i == 1) {
            int x;
            cin >> x;
            if (tr[1].sum < x) {
                cout << 0 << endl;
                continue;
            }
            int ans = query(1,1,n,x);
            cout << ans << endl;
            add(1,ans,ans + x - 1,1);
        } else {
            int x,y;
            cin >> x >> y;
            add(1,x,x + y - 1,2);
        }
    }
    return 0;
}