#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N = 2e5 + 5;
int a[N],dp[N][2]; // dp[i][0/1] 表示让 1 - i / i - n 严格 递增 / 递减 的方案数

signed main() {
    int n,ans = 1e18;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 2;i <= n;i++) {
        if (a[i] > a[i - 1]) dp[i][0] = dp[i - 1][0];
        else dp[i][0] = dp[i - 1][0] - a[i] + a[i - 1] + 1;
    }
    for (int i = n;i >= 2;i--) {
        if (a[i] < a[i - 1]) dp[i][1] = dp[i + 1][1];
        else dp[i][1] = dp[i + 1][1] + a[i] - a[i - 1] + 1;
    }
    for (int i = 1;i <= n;i++) ans = min(ans,max(dp[i][0],dp[i + 1][1]));
    cout << ans << endl;
    return 0;
}