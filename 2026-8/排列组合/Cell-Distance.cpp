#include<iostream>
#define int long long
using namespace std;

const int N = 2e5 + 5,mod = 1e9 + 7;
int f[N],g[N],n,m,k;

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
    int k = n * m - 2;
    for (int i = 1;i <= k;i++) f[i] = f[i - 1] * i % mod;
    g[k] = qpow(f[k],mod - 2,mod);
    for (int i = k - 1;i >= 1;i--)
        g[i] = g[i + 1] * (i + 1) % mod;
}

long long query(long long n,long long m) 
{return f[n] * g[m] % mod * g[n - m] % mod;}

signed main() {
    cin >> n >> m >> k;
    init();
    long long ans = 0;
    for (int i = 1;i < n;i++)
        ans += i * (n - i) % mod * m % mod * m % mod, ans %= mod;
    for (int i = 1;i < m;i++)
        ans += i * (m - i) % mod * n % mod * n % mod, ans %= mod;
    ans *= query(n * m - 2,k - 2), ans %= mod;
    cout << ans << endl;
    return 0;
}