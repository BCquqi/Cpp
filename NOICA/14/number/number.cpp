#include<iostream>
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

void solve() {
    ll n,p;
    cin >> n >> p;
    cout << (qpow(3,n,p) - qpow(2,n,p) + p) % p << ' ';
    cout << n % p * (qpow(2,2 * n - 1,p) - qpow(3,n - 1,p) + p) % p << endl;
    return ;
}

int main() {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}