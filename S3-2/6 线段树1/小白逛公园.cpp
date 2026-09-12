#include<iostream>
#define lid id * 2
#define rid id * 2 + 1
using namespace std;

const int N = 5e5 + 5;
struct seg_tree {int l,r,sum,max,mxl,mxr;} tr[N << 2];
int n,m,a[N];

void pushup(int id) {
    if (tr[lid].mxr < 0 && tr[rid].mxl < 0)
        tr[id].max = max(tr[lid].mxr,tr[rid].mxl);
    else tr[id].max = max(tr[lid].mxr,0) + max(tr[rid].mxl,0);
    tr[id].max = max(tr[id].max,max(tr[lid].max,tr[rid].max)), 
    tr[id].mxl = max(tr[lid].mxl,tr[lid].sum + tr[rid].mxl), 
    tr[id].mxr = max(tr[rid].mxr,tr[rid].sum + tr[lid].mxr), 
    tr[id].sum = tr[lid].sum + tr[rid].sum;
}

void build(int id,int l,int r) {
    tr[id].l = l, tr[id].r = r;
    if (l == r) {
        tr[id].sum = tr[id].mxl = tr[id].mxr = tr[id].max = a[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(lid,l,mid);
    build(rid,mid + 1,r);
    pushup(id);
    return ;
}

void modify(int id,int p,int s) {
    if (tr[id].l == tr[id].r) {
        tr[id].sum = tr[id].mxl = tr[id].mxr = tr[id].max = s;
        return ;
    }
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (p <= mid) modify(lid,p,s);
    else modify(rid,p,s);
    pushup(id);
    return ;
}

seg_tree query(int id,int l,int r) {
    if (l <= tr[id].l && tr[id].r <= r) return tr[id];
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (r <= mid) return query(lid,l,r);
    if (l > mid) return query(rid,l,r);
    seg_tree ql = query(lid,l,mid), qr = query(rid,mid + 1,r),res;
    res.l = ql.l, res.r = qr.r;
    res.sum = ql.sum + qr.sum;
    res.mxl = max(ql.mxl,ql.sum + qr.mxl);
    res.mxr = max(qr.mxr,qr.sum + ql.mxr);
    res.max = max(max(ql.max,qr.max),ql.mxr + qr.mxl);
    return res;
}

int main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    build(1,1,n);
    while (m--) {
        int k;
        cin >> k;
        if (k == 1) {
            int a,b;
            cin >> a >> b;
            if (a > b) swap(a,b);
            cout << query(1,a,b).max << endl;
        } else {
            int p,s;
            cin >> p >> s;
            modify(1,p,s);
        }
    }
    return 0;
}