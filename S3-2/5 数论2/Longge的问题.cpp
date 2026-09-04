#include<iostream>
using namespace std;
typedef long long ll;

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
    ll n;
    cin >> n;
    ll ans = 0;
    for (int i = 1;i * i <= n;i++)
        if (n % i == 0) {
            ans += i * phi(n / i);
            if (i * i != n) ans += (n / i) * phi(i);
        }
    cout << ans << endl;
    return 0;
}