#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N = 2005,mod = 1e9 + 9;
int a[N],b[N],f[N],g[N],n,k,pos[N],dp[N][N];
// dp[i][j] 表示前 i 个中选了 j 组满足 a > b 的方案数

long long qpow(long long a,long long b,long long p) {
    long long ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

void init() {
    f[0] = g[0] = 1;
    int mx = n;
    for (int i = 1;i <= mx;i++) f[i] = f[i - 1] * i % mod;
    g[mx] = qpow(f[mx],mod - 2,mod);
    for (int i = mx - 1;i >= 1;i--)
        g[i] = g[i + 1] * (i + 1) % mod;
    int cur = 0;
    for (int i = 1;i <= n;i++) {
        while (cur < n && b[cur + 1] < a[i]) ++cur;
        pos[i] = cur;
    }
}

long long query(long long n,long long m) 
{return f[n] * g[m] % mod * g[n - m] % mod;}

signed main() {
    cin >> n >> k;
    int p = (n + k) / 2;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++) cin >> b[i];
    sort(a + 1,a + n + 1); sort(b + 1,b + n + 1);
    init();
    dp[0][0] = 1;
    for (int i = 1;i <= n;i++) {
        dp[i][0] = dp[i - 1][0];
        for (int j = 1;j <= i;j++)
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1] * max(pos[i] - j + 1,0ll) % mod) % mod;
    }
    long long ans = 0;
    for (int i = p;i <= n;i++)
        if ((i - p) % 2) ans -= query(i,p) * dp[n][i] % mod * f[n - i] % mod;
        else ans += query(i,p) * dp[n][i] % mod * f[n - i] % mod;
    cout << (ans + mod + mod + mod) % mod << endl;
    return 0;
}