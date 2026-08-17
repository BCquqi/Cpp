#include<iostream>
#define int long long
using namespace std;

const int N = 2e6 + 5,mod = 1e9 + 7;
int f[N],g[N],h[N];

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
    int k = 2e6;
    for (int i = 1;i <= k;i++) f[i] = f[i - 1] * i % mod;
    g[k] = qpow(f[k],mod - 2,mod);
    for (int i = k - 1;i >= 1;i--)
        g[i] = g[i + 1] * (i + 1) % mod;
    h[1] = 0,h[2] = 1,h[3] = 2;
    for (int i = 4;i <= k;i++) h[i] = (h[i - 1] + h[i - 2]) % mod * (i - 1) % mod;
}

long long query(long long n,long long m) 
{return f[n] * g[m] % mod * g[n - m] % mod;}

void solve() {
    int n,m;
    cin >> n >> m;
    if (n == m) cout << 1 << endl;
    else cout << query(n,m) * h[n - m] % mod << endl;
    return ;
}

signed main() {
    int T;
    cin >> T;
    init();
    while (T--) solve();
    return 0;
}