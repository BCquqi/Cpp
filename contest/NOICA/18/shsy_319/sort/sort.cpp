#include<iostream>
using namespace std;

const int N = 2005,mod = 1e9 + 7;
int fac[N],ifac[N];
int f[N][N],p[N][N],g[N];

int qpow(int a,int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return res;
}

int C(int n,int m) {
    if (m < 0 || m > n) return 0;
    return 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("sort.in","r",stdin);
    freopen("sort.out","w",stdout);
    int n;
    cin >> n;
    fac[0] = 1;
    for (int i = 1;i <= n;i++) fac[i] = 1ll * fac[i - 1] * i % mod;
    ifac[n] = qpow(fac[n],mod - 2);
    for (int i = n - 1;i >= 0;i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
    for (int i = 1;i <= n;i++) {
        int sum = 0;
        for (int j = 1;j < i;j++)
            f[i][j] = 1ll * C(i - 1,i - j) * f[j][j] % mod, 
            sum = (sum + f[i][j]) % mod;
        f[i][i] = (fac[i] - sum + mod) % mod;
    }
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= i;j++)
            p[i][j] = 1ll * f[i][j] * ifac[i] % mod;
    g[1] = 0;
    for (int i = 2;i <= n;i++) {
        int sum = p[i][i];
        for (int j = 1;j < i;j++)
            sum = (sum + 1ll * (g[j] + 1) * p[i][j]) % mod;
        g[i] = 1ll * sum * qpow((1 - p[i][i] + mod) % mod,mod - 2) % mod;
    }
    int ans = 0;
    for (int i = 1;i <= n;i++)
        ans = (ans + 1ll * (g[i] + 1) * p[n][i]) % mod;
    cout << ans - 1 << endl;
    return 0;
}