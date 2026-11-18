#include<iostream>
#include<algorithm>
#include<cstdio>
#define int long long
using namespace std;

const int N = 2e5 + 5;
int a[N],cpy[N],p[N],q[N],dp[N],tmp[N],tree[2][N * 2];
int n,lim;

int lowbit(int x) {return x & -x;}

void add(int x,int v,int op)
{while (x <= lim) tree[op][x] = max(tree[op][x],v),x += lowbit(x);}

int query(int x,int op) {
    int ret = -1e18;
    while (x) ret = max(ret,tree[op][x]),x -= lowbit(x);
    return ret;
}

void clear(int x,int op)
{while (x <= lim) tree[op][x] = -1e18,x += lowbit(x);}

void cdq(int l,int r) {
    if (l == r) return ;
    int mid = (l + r) >> 1;
    cdq(l, mid);
    for (int i = l;i <= r;i++) tmp[i] = i;
    sort(tmp + l,tmp + mid + 1,[](int x,int y) {return p[x] < p[y];});
    sort(tmp + mid + 1,tmp + r + 1,[](int x,int y) {return p[x] < p[y];});
    int i = l, j = mid + 1;
    while (j <= r) {
        while (i <= mid && p[tmp[i]] < p[tmp[j]]) {
            add(q[tmp[i]] + n + 1,dp[tmp[i]],tmp[i] & 1);
            i++;
        }
        int res = query(q[tmp[j]] + n,(tmp[j] & 1) ^ 1);
        dp[tmp[j]] = max(dp[tmp[j]],res + 1);
        j++;
    }
    for (int k = l;k < i;k++) clear(q[tmp[k]] + n + 1,tmp[k] & 1);
    cdq(mid + 1,r);
    return ;
}

void solve() {
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i],cpy[i] = a[i];
    sort(cpy + 1,cpy + n + 1);
    int m = cpy[n / 2 + 1];
    int cnt = 0,val = 0;
    for (int i = 1;i <= n;i++) {
        if (a[i] < m) val--;
        else if (a[i] == m) cnt++;
        else val++;
        p[i] = cnt + val, q[i] = cnt - val;
    }
    p[0] = 0, q[0] = 0;
    lim = 2 * n + 5;
    for (int i = 0;i <= lim;i++) tree[0][i] = tree[1][i] = -1e18;
    for (int i = 0;i <= n;i++) dp[i] = -1e18;
    dp[0] = 0;
    cdq(0,n);
    cout << dp[n] << endl;
    return ;
}

signed main() {
    freopen("refrain.in","r",stdin);
    freopen("refrain.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}