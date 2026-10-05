#include <iostream>
#include <cstring>
#define int long long
using namespace std;

const int N = 20, M = 4e6 + 5;
int n, k, l, r, ans;
int a[N], b[M], dp[M];

void init() {
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= n; j++)
            if (((i + a[j] - 1) / a[j]) & 1) b[i] |= (1 << (j - 1));
    return ;
}

inline int popcount(int x) {
    int cnt = 0;
    while (x)
        cnt += x & 1, x >>= 1;
    return cnt;
}

bool check(int mid) {
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= mid; i++) dp[b[i]]++;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < (1 << n); j++)
            if (((j >> i) & 1) == 0) dp[j | (1 << i)] += dp[j];
    for (int i = 0; i < (1 << n); i++)
        if (mid - dp[(1 << n) - 1 - i] < popcount(i) * k) return false;
    return true;
}

signed main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    l = 1, r = 2 * n * k, ans = 0;
    init();
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}