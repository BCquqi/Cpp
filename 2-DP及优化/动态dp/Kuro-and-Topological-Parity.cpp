#include<iostream>
#define int long long
using namespace std;

const int N = 55,mod = 1e9 + 7;
int dp[N][N][N][N],po[N],a[N],n,p;
long long ans = 0;

void init() {
    if (a[1] == -1 || a[1] == 0)
        dp[1][0][1][0] = 1, ans += (p == 1 && n == 1);
    if (a[1] == -1 || a[1] == 1)
        dp[1][1][0][0] = 1, ans += (p == 1 && n == 1);
    return ;
}

signed main() {
    cin >> n >> p;
    po[0] = 1;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        po[i] = po[i - 1] * 2 % mod;
    }
    init();
    for (int i = 2;i <= n;i++)
        for (int j = 0;j <= i;j++)
            for (int k = 0;k <= i - j;k++)
                for (int l = 0;l <= i - j - k;l++) {
                    int m = i - j - k - l;
                    if (a[i] == -1 || a[i] == 1) {
                        long long tmp = 0;
                        if (j)
                            if (k) tmp += dp[i - 1][j - 1][k][l] * po[k - 1] % mod;
                            else tmp += dp[i - 1][j - 1][k][l];
                        tmp %= mod;
                        if (l && k) tmp += dp[i - 1][j][k][l - 1] * po[k - 1] % mod, tmp %= mod;
                        tmp *= po[j + l + m - 1], tmp %= mod;
                        dp[i][j][k][l] += tmp, dp[i][j][k][l] %= mod;
                    }
                    if (a[i] == -1 || a[i] == 0) {
                        long long tmp = 0;
                        if (k)
                            if (j) tmp += dp[i - 1][j][k - 1][l] * po[j - 1] % mod;
                            else tmp += dp[i - 1][j][k - 1][l];
                        tmp %= mod;
                        if (m && j) tmp += dp[i - 1][j][k][l] * po[j - 1] % mod, tmp %= mod;
                        tmp *= po[k + l + m - 1], tmp %= mod;
                        dp[i][j][k][l] += tmp, dp[i][j][k][l] %= mod;
                    }
                    if (i == n && ((j + k) % 2 == p)) ans += dp[i][j][k][l], ans %= mod;
                }
    cout << ans << endl;
    return 0;
}