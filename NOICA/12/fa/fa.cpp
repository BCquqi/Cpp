#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N = 5e4 + 6,M = 15,mod = 998244353;
int n,m,x,y,a[M],cnt[M],dp[11];
bool b[1 << 10];

signed main() {
    freopen("fa.in","r",stdin);
    freopen("fa.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    while (m--) {
        cin >> x >> y;
        a[x] |= 1 << y,a[y] |= 1 << x;
    }
    b[0] = true;
    for (int i = 1;i < 1 << 10;i++) {
        int x = __builtin_ctz(i),y = i & (i - 1);
        b[i] = (b[y] && ((a[x] & y) == y));
        if (b[i]) cnt[__builtin_popcount(i)]++;
    }
    dp[0] = 1;
    for (int i = 1;i <= n;i++) {
        dp[i % 11] = 0;
        for (int j = 1;j <= min(10ll,i);j++)
            if (j % 2 == 1) dp[i % 11] = (dp[i % 11] + cnt[j] * dp[(i - j) % 11]) % mod;
            else dp[i % 11] = (dp[i % 11] - cnt[j] * dp[(i - j) % 11]) % mod;
    }
    cout << (dp[n % 11] + mod) % mod << endl;
    return 0;
}