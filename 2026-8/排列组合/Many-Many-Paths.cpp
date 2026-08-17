#include<iostream>
using namespace std;

const int mod = 1e9 + 7,N = 2e6 + 5;
int r1,c1,r2,c2;
long long f[N],g[N];

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
    int k = r2 + c2 + 2;
    for (int i = 1;i <= k;i++) f[i] = f[i - 1] * i % mod;
    g[k] = qpow(f[k],mod - 2,mod);
    for (int i = k - 1;i >= 1;i--)
        g[i] = g[i + 1] * (i + 1) % mod;
}

long long query(long long n,long long m) 
{return f[n] * g[m] % mod * g[n - m] % mod;}

int main() {
    cin >> r1 >> c1 >> r2 >> c2;
    init();
    cout << (((1ll * query(r2 + c2 + 2,c2 + 1) - query(c2 + r1 + 1,c2 + 1) + mod) % mod - query(r2 + c1 + 1,c1) + mod) % mod + query(r1 + c1,c1)) % mod << endl;
    return 0;
}
