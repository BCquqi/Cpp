#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
int ls[N * 20],rs[N * 20],mx[N * 20],rt[N],tot;

int query(int u,int l,int r,int ql,int qr) {
    if ((!u) || ql > qr || l > r) return 0;
    if (ql <= l && r <= qr) return mx[u];
    int mid = (l + r) >> 1,res = 0;
    if (ql <= mid) res = query(ls[u],l,mid,ql,qr);
    if (qr > mid) res = max(res,query(rs[u],mid + 1,r,ql,qr));
    return res;
}

void modify(int &u,int l,int r,int pos,int v) {
    if (!u) u = ++tot;
    if (l == r) {
        mx[u] = max(mx[u],v);
        return ;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) modify(ls[u],l,mid,pos,v);
    else modify(rs[u],mid + 1,r,pos,v);
    mx[u] = max(mx[ls[u]],mx[rs[u]]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,m;
    cin >> n >> m;
    int ans = 0;
    while (m--) {
        int a,b,k;
        cin >> a >> b >> k;
        int f = query(rt[a],0,100000,0,k - 1) + 1;
        modify(rt[b],0,100000,k,f);
        ans = max(ans,f);
    }
    cout << ans << endl;
    return 0;
}