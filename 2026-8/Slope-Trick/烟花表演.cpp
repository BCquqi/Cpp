#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N = 2e6 + 5;
int p[N],c[N],d[N],rt[N],ans = 0;
int val[N],ls[N],rs[N],dis[N],idx = 0;

inline int merge(int x,int y) {
    if (!x || !y) return x + y;
    if (val[x] < val[y]) swap(x,y);
    rs[x] = merge(rs[x],y);
    if (dis[ls[x]] < dis[rs[x]]) swap(ls[x],rs[x]);
    dis[x] = dis[rs[x]] + 1;
    return x;
}

inline void pop(int &u) {u = merge(ls[u],rs[u]);}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 2;i <= n + m;i++) {
        cin >> p[i] >> c[i];
        d[p[i]]++, ans += c[i];
    }
    for (int i = n + m;i >= 2;i--) {
        for (int j = 1;j < d[i];j++) pop(rt[i]);
        int l = 0,r = 0;
        if (i <= n) r = val[rt[i]], pop(rt[i]), l = val[rt[i]], pop(rt[i]);
        val[++idx] = l + c[i], ls[idx] = rs[idx] = 0, dis[idx] = 0, 
        val[++idx] = r + c[i], ls[idx] = rs[idx] = 0, dis[idx] = 0;
        rt[i] = merge(rt[i], merge(idx, idx - 1)), 
        rt[p[i]] = merge(rt[p[i]], rt[i]);
    }
    while (d[1]--) pop(rt[1]);
    while (rt[1]) ans -= val[rt[1]], pop(rt[1]);
    cout << ans << endl;
    return 0;
}