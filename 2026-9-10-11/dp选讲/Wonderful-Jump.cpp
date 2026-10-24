#include <iostream>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;

const int N = 4e5 + 5;
int a[N], dp[N];

signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(dp,0x3f,sizeof dp);
    dp[1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; i - j <= n / a[i] && j >= 1; j--) {
            dp[i] = min(dp[i], dp[j] + a[i] * (i - j) * (i - j));
            if (a[j] <= a[i]) break;
        }
        for (int j = i + 1; j - i <= n / a[i] && j <= n && a[j] > a[i]; j++) {
            dp[j] = min(dp[j], dp[i] + a[i] * (j - i) * (j - i));
            if (a[j] <= a[i]) break;
        }
    }
    for (int i = 1;i <= n;i++) cout << dp[i] << ' ';
    cout << endl;
    return 0;
}