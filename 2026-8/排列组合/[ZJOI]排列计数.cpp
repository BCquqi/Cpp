#include<iostream>
#define int long long
using namespace std;

const int N = 2e6 + 5;
int n,m,siz[N],fac[N];

long long qpow(long long a,long long b,long long p) {
    long long ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

void init(int u) {
    if (u > n) return ;
    siz[u] = 1;
    init(2 * u); init(2 * u + 1);
    siz[u] += siz[2 * u] + siz[2 * u + 1];
    return ;
}

int query(int a,int b,int p) {
    if (b == 0) return 1;
    return fac[a % p] * qpow(fac[b % p] * fac[a % p - b % p] % p,p - 2,p) % p * query(a / p,b / p,p) % p;
}

int dfs(int u) {
    if (u > n) return 1;
    return query(siz[u] - 1,siz[u * 2],m) * dfs(u * 2) % m * dfs(u * 2 + 1) % m;
}

signed main() {
    cin >> n >> m;
    fac[0] = 1;
    for (int i = 1;i <= n;i++) fac[i] = fac[i - 1] * i % m;
    init(1);
    cout << dfs(1) << endl;
    return 0;
}