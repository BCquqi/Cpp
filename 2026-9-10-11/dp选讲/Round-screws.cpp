#include <iostream>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;

const int N = 2e5 + 5;
int T, n, C, ans;
int a[N], dp[N], f[605][605];

inline void modify(int x, int y) {
    for (int i = 0; i < (1 << 9); i++)
        f[x >> 9][i] = min(f[x >> 9][i], (i ^ (x & ((1 << 9) - 1))) + y);
    return ;
}

inline int query(int x) {
    int ret = 1e18;
    for (int i = 0; i < (1 << 9); i++)
        ret = min(ret, f[i][x & ((1 << 9) - 1)] + ((i ^ (x >> 9)) << 9) - C);
    return ret;
}

void solve() {
    cin >> n >> C;
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[0] = a[n + 1] = 0;
    memset(dp, 0x3f, sizeof dp);
    memset(f, 0x3f, sizeof f);
    dp[0] = C * (n + 1);
    modify(0, dp[0]);
    for (int i = 1; i <= n + 1; i++) {
        dp[i] = query(a[i]);
        modify(a[i], dp[i]);
    }
    cout << dp[n + 1] << endl;
}

signed main() {
    cin >> T;
    while (T--) solve();
    return 0;
}