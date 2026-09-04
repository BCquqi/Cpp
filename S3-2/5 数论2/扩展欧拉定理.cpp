#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

ll qpow(ll a,ll b,ll p) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

ll phi(ll x) {
    ll res = x;
    for (int i = 2;1ll * i * i <= x;i++) {
        if (x % i) continue;
        while (x % i == 0) x /= i;
        res = res / i * (i - 1);
    }
    if (x > 1) res = res / x * (x - 1);
    return res;
}

int main() {
    ll a,m; string b;
    cin >> a >> m >> b;
    ll Phi = phi(m);
    ll c = 0;
    for (int i = 0;i < b.size();i++)
        c = c * 10 + b[i] - '0', c %= Phi;
    if (__gcd(a,m) == 1) cout << qpow(a,c,m) << endl;
    else if (b == to_string(c)) cout << qpow(a,c,m) << endl;
    else cout << qpow(a,c + Phi,m) << endl;
    return 0;
}