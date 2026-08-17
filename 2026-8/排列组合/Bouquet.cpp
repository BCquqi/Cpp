#include<iostream>
#define int long long
using namespace std;

// 2^n - C(n,a) - C(n,b) - 1

const int mod = 1e9 + 7;

long long qpow(long long a,long long b,long long p) {
    long long ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

long long C(long long a,long long b) {
    long long ans = 1;
    for (int i = 1;i <= b;i++)
        ans *= (a - b + i), ans %= mod, 
        ans *= qpow(i,mod - 2,mod), ans %= mod;
    return ans; 
}

signed main() {
    int n,a,b;
    cin >> n >> a >> b;
    cout << (qpow(2,n,mod) - C(n,a) - C(n,b) - 1 + mod + mod) % mod << endl;
    return 0;
} 
