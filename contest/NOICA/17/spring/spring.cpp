#include<iostream>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;

const int N = 3005;
struct Node {int l,r;} a[N];
int dp[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("spring.in","r",stdin);
    freopen("spring.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i].l >> a[i].r;
    sort(a + 1,a + n + 1,[](Node x,Node y) {return x.l != y.l ? x.l < y.l : x.r < y.r;});
    memset(dp,0x3f,sizeof dp);
    dp[0] = 0;
    for (int j = 0;j < m;j++) {
        if (dp[j] > 1e18) continue;
        for (int i = 1;i <= n;i++) {
            int k = max(0ll,max(a[i].l - j - 1,j + 1 - a[i].r));
            if (a[i].r + k < m) dp[a[i].r + k] = min(dp[a[i].r + k],dp[j] + k);
            dp[m] = min(dp[m],dp[j] + max(0ll,max(a[i].l - j - 1,m - a[i].r)));
        }
    }
    cout << dp[m] << endl;
    return 0;
}