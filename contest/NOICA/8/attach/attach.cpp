#include<iostream>
#include<algorithm>
#define lid id << 1
#define rid id << 1 | 1
using namespace std;

const int N = 5e5 + 5;
int p[N],q[N],pos[N];

struct seg_tree {int l,r,lazy,mn;} tr[N << 2];

void pushup(int id) {
    tr[id].mn = min(tr[lid].mn,tr[rid].mn);
    return ;
}

void build(int id,int l,int r) {
    tr[id].l = l,tr[id].r = r;
    if (l == r) {
        tr[id].mn = 0;
        return ;
    }
    int mid = (l + r) >> 1;
    build(lid,l,mid);
    build(rid,mid + 1,r);
    pushup(id);
}

void pushdown(int id) {
    if (tr[id].lazy && tr[id].l != tr[id].r) {
        tr[lid].mn += tr[id].lazy, tr[rid].mn += tr[id].lazy;
        tr[lid].lazy += tr[id].lazy, tr[rid].lazy += tr[id].lazy;
        tr[id].lazy = 0;
    }
}

void modify(int id,int l,int r,int val) {
    if (l <= tr[id].l && tr[id].r <= r) {
        tr[id].lazy += val, tr[id].mn += val;
        return ;
    }
    pushdown(id);
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (r <= mid) modify(lid,l,r,val);
    else if (l > mid) modify(rid,l,r,val);
    else modify(lid,l,mid,val), modify(rid,mid + 1,r,val);
    pushup(id);
}

int query(int id,int l,int r) {
    if (l > r) return 0;
    if (l <= tr[id].l && tr[id].r <= r) return tr[id].mn;
    pushdown(id);
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (r <= mid) return query(lid,l,r);
    else if (l > mid) return query(rid,l,r);
    else return min(query(lid,l,mid),query(rid,mid + 1,r));
}

int main() {
    freopen("attach.in","r",stdin);
    freopen("attach.out","w",stdout);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    for (int i = 1;i <= n;i++) cin >> q[i];
    build(1,1,n);
    int ans = n;
    for (int i = 1;i <= n;i++) {
        while (ans > 0 && query(1,pos[ans],n) - min(query(1,1,pos[ans] - 1),0) < 0) {
            modify(1,pos[ans],n,1);
            ans--;
        }
        cout << ans << ' ';
        modify(1,q[i],n,-1);
    }
    return 0;
}