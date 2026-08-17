#include<iostream>
#include<algorithm>
#include<cstdio>
#define int long long
using namespace std;

const int N = 2e6 + 5,mod = 20100403;
int n,m,f[N],g[N];

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
    int k = n + m;
    for (int i = 1;i <= k;i++) f[i] = f[i - 1] * i % mod;
    g[k] = qpow(f[k],mod - 2,mod);
    for (int i = k - 1;i >= 1;i--)
        g[i] = g[i + 1] * (i + 1) % mod;
}

long long query(long long n,long long m) 
{return f[n] * g[m] % mod * g[n - m] % mod;}

signed main() {
    cin >> n >> m;
    init();
    cout << (query(n + m,m) - query(n + m,m - 1) + mod) % mod << endl;
    return 0;
}