#include<iostream>
#include<cstring>
#define lid id * 2
#define rid id * 2 + 1
using namespace std;

const int N = 3.5e4 + 5;
int a[N],pre[N],last[N],dp[55][N];

struct seg_tree {int l,r,lazy,maxn;} tr[N << 2];

void build(int id,int l,int r,int x) {
    tr[id].l = l,tr[id].r = r;
    if (l == r) {
        tr[id].maxn = dp[x][l - 1];
        return ;
    }
    int mid = (l + r) >> 1;
    build(lid,l,mid,x);
    build(rid,mid + 1,r,x);
    tr[id].maxn = max(tr[lid].maxn,tr[rid].maxn);
}

void pushdown(int id) {
    if (tr[id].lazy && tr[id].l != tr[id].r) {
        tr[lid].lazy += tr[id].lazy;
        tr[rid].lazy += tr[id].lazy;
        tr[lid].maxn += tr[id].lazy;
        tr[rid].maxn += tr[id].lazy;
        tr[id].lazy = 0;
    }
}

void modify(int id,int l,int r,int val) {
    if (l <= tr[id].l && tr[id].r <= r) {
        tr[id].lazy += val;
        tr[id].maxn += val;
        return ;
    }
    pushdown(id);
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (r <= mid) modify(lid,l,r,val);
    else if (l > mid) modify(rid,l,r,val);
    else modify(lid,l,mid,val), modify(rid,mid + 1,r,val);
    tr[id].maxn = max(tr[lid].maxn,tr[rid].maxn);
}

int query(int id,int l,int r) {
    pushdown(id);
    if (tr[id].l == l && tr[id].r == r) return tr[id].maxn;
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (r <= mid) return query(lid,l,r);
    else if (l > mid) return query(rid,l,r);
    else return max(query(lid,l,mid),query(rid,mid + 1,r));
}

int main() {
    int n,k;
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        pre[i] = last[a[i]] + 1, last[a[i]] = i;
    }
    for (int i = 1;i <= k;i++) {
        memset(tr,0,sizeof tr);
        build(1,1,n,i - 1);
        for (int j = 1;j <= n;j++) {
            modify(1,pre[j],j,1);
            dp[i][j] = query(1,1,j);
        }
    }
    cout << dp[k][n] << endl;
    return 0;
}