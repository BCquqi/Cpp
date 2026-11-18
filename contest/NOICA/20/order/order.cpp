#include<iostream>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;

const int N = 1e3 + 5,M = 105;
int n,k;
int a[N],ans[M];
int dp[M][1 << 5][1 << 4][2],f[M][1 << 5][1 << 4][6][2];

int get(int l,int r) {
    l = max(l,0ll);
    if (l > r) return 0;
    return ((1 << l) - 1) ^ ((1 << r + 1) - 1);
}

int calc(int u) {return (u == 0 || u == 5) ? 0 : (1 << u - 1);}

inline void upd(int &u,int v) {u = max(u,v);}

void solve() {
    cin >> n >> k;
    for (int i = 1;i <= n;i++) cin >> a[i];
    memset(f,-0x3f,sizeof f);
    for (int i = 0;i < 6;i++) f[1][0][calc(i)][i][0] = 1;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= k;j++)
            for (int s1 = 0;s1 < 1 << 5;s1++)
                for (int s2 = 0;s2 < 1 << 4;s2++) {
                    dp[j][s1][s2][0] = f[j][s1][s2][a[i]][0];
                    dp[j][s1][s2][1] = f[j][s1][s2][a[i]][1];
                    upd(ans[j],max(dp[j][s1][s2][0],dp[j][s1][s2][1]));
                }
        for (int j = 1;j <= k;j++)
            for (int s1 = 0;s1 < 1 << 5;s1++)
                for (int s2 = 0;s2 < 1 << 4;s2++) {
                    for (int v = 0;v < 6;v++)
                        if (v == 0 || v == 5 || (s2 & (1 << v - 1)) || !(s1 & (1 << v))) 
                            upd(f[j + 1][s1][s2 | calc(v) | calc(a[i])][v][0],max(dp[j][s1][s2][0],dp[j][s1][s2][1]) + 1);
                    for (int v = a[i];v < 6;v++) {
                        if (!(get(a[i],v - 1) & s1) && !(get(a[i],v - 2) & s2)) 
                            upd(f[j][s1 | get(a[i],v - 1)][s2][v][1],dp[j][s1][s2][0] + 1);
                        if (!(get(a[i],v - 1) & s1) && !(get(a[i] - 1,v - 2) & s2)) 
                            upd(f[j][s1 | get(a[i],v - 1)][s2][v][1],dp[j][s1][s2][1] + 1);
                    }
                    upd(f[j][s1][s2][a[i]][0],dp[j][s1][s2][0] + 1);
                }
    }
    for (int i = 1;i <= k;i++) cout << ans[i] << ' ';
    cout << endl;
    return ;
}

signed main() {
    freopen("order.in","r",stdin);
    freopen("order.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}