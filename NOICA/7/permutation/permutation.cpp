#include<iostream>
#include<algorithm>
#include<cstring>
#define lid id * 2
#define rid id * 2 + 1
#define int long long
using namespace std;

const int N = 5e5 + 5;
const long long INF = 1e18;
int a[N],pos[N],L[N],R[N],n,m;
long long dp[2][N];
struct seg_tree {int l,r; long long mn;} tr[N << 2];

void build(int id,int l,int r) {
    tr[id].l = l, tr[id].r = r, tr[id].mn = INF;
    if (l == r) {
        tr[id].mn = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lid,l,mid);
    build(rid,mid + 1,r);
    tr[id].mn = min(tr[lid].mn,tr[rid].mn);
}

void modify(int id,int pos,int val) {
    if (tr[id].l == tr[id].r) {
        tr[id].mn = val;
        return;
    }
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (pos <= mid) modify(lid,pos,val);
    else modify(rid,pos,val);
    tr[id].mn = min(tr[lid].mn,tr[rid].mn);
}

int query(int id, int l, int r) {
    if (tr[id].l > r || tr[id].r < l) return INF;
    if (l <= tr[id].l && tr[id].r <= r) return tr[id].mn;
    int mid = (tr[id].l + tr[id].r) >> 1;
    return min(query(lid,l,r),query(rid,l,r));
}

int get(int s) {
    if (m == n) return INF;
    int ret = INF;
    if (s + m <= n + 1) {
        if (s > 1) ret = min(ret,query(1,1,s - 1));
        if (s + m <= n) ret = min(ret,query(1,s + m,n));
        return ret;
    }
    int left = (s + m - 1) % n + 1;
    int right = (s - 2 + n) % n + 1;
    if (left <= right) return query(1,left,right);
    return INF;
}

signed main() {
    freopen("permutation.in","r",stdin);
    freopen("permutation.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 1;i <= n;i++)
        L[i] = pos[i], R[i] = (pos[i] - m + n) % n + 1;
    L[0] = 1, R[0] = 1;
    for (int i = 0;i <= n;i++) dp[0][i] = dp[1][i] = INF;
    dp[0][0] = 0;
    build(1,1,n);
    int ans = INF;
    for (int k = 0;k <= n;k++) {
        if (k > 1) modify(1,pos[k - 1],INF);
        if (dp[0][k] < INF) {
            int tmp = get(L[k]);
            if (tmp == INF) ans = min(ans,dp[0][k]);
            else
                dp[0][tmp] = min(dp[0][tmp],dp[0][k] + (L[k] - L[tmp] + n) % n), 
                dp[1][tmp] = min(dp[1][tmp],dp[0][k] + (R[tmp] - L[k] + n) % n);
        }
        if (dp[1][k] < INF) {
            int tmp = get(R[k]);
            if (tmp == INF) ans = min(ans,dp[1][k]);
            else
                dp[0][tmp] = min(dp[0][tmp],dp[1][k] + (R[k] - L[tmp] + n) % n), 
                dp[1][tmp] = min(dp[1][tmp],dp[1][k] + (R[tmp] - R[k] + n) % n);
        }
    }
    cout << ans << endl;
    return 0;
}