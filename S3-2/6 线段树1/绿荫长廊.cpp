#include<iostream>
#include<cstring>
#define lid id << 1
#define rid id << 1 | 1
using namespace std;

const int N = 5e5 + 5;
bool c[N];
struct seg_tree {int id,l,r,ans,ansl,ansr;} tr[N << 2];

void pushup(int id) {
    tr[id].ans = max(max(tr[lid].ans,tr[rid].ans),tr[lid].ansr + tr[rid].ansl), 
    tr[id].ansl = (tr[lid].ansl == tr[lid].r - tr[lid].l + 1 ? tr[lid].ansl + tr[rid].ansl : tr[lid].ansl), 
    tr[id].ansr = (tr[rid].ansr == tr[rid].r - tr[rid].l + 1 ? tr[rid].ansr + tr[lid].ansr : tr[rid].ansr);
}

void build(int id,int l,int r) {
    tr[id].l = l, tr[id].r = r;
    if (l == r) {
        tr[id].ans = tr[id].ansl = tr[id].ansr = c[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(lid,l,mid);
    build(rid,mid + 1,r);
    pushup(id);
    return ;
}

seg_tree query(int id,int l,int r) {
    if (l <= tr[id].l && tr[id].r <= r) return tr[id];
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (r <= mid) return query(lid,l,r);
    if (l > mid) return query(rid,l,r);
    seg_tree ql = query(lid,l,mid), qr = query(rid,mid + 1,r);
    seg_tree res;
    res.l = ql.l, res.r = qr.r;
    res.ansl = (ql.ansl == ql.r - ql.l + 1 ? ql.ansl + qr.ansl : ql.ansl), 
    res.ansr = (qr.ansr == qr.r - qr.l + 1 ? ql.ansr + qr.ansr : qr.ansr), 
    res.ans = max(max(ql.ans,qr.ans),ql.ansr + qr.ansl);
    return res;
}

int main() {
    int l;
    cin >> l;
    for (int i = 1;i <= l;i++) cin >> c[i];
    build(1,1,l);
    int q;
    cin >> q;
    while (q--) {
        int a,b;
        cin >> a >> b;
        cout << query(1,a,b).ans << endl;
    }
    return 0;
}