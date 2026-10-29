#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N = 5005,mod = 998244353;
int a[N],dp[N],pw[N],n;

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + n + 1);
    pw[0] = 1;
    for (int i = 1;i <= n;i++) pw[i] = pw[i - 1] * 2 % mod;
    dp[0] = 1;
    int ans = 0;
    for (int i = 1;i <= n;i++) {
        int sum = 0;
        for (int j = 0;j <= a[i];j++) sum = (sum + dp[j]) % mod;
        ans = (ans + pw[i - 1] - sum + mod) % mod;
        for (int j = 5000;j >= a[i];j--) dp[j] = (dp[j] + dp[j - a[i]]) % mod;
    }
    cout << ans << endl;
    return 0;
}