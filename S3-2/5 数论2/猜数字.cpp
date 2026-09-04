#include<iostream>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
int a[N],b[N];

ll exgcd(ll a,ll b,ll &x,ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b,a % b,x,y),t = x;
    x = y, y = (t - a / b * y);
    return d;
}

ll inv(ll a,ll m) {
    ll x,y;
    exgcd(a,m,x,y);
    return (x + m) % m;
}

ll mul(ll a,ll b,ll p) {
    ll ans = 0;
    if (b < 0) a = -a, b = -b;
    while (b) {
        if (b & 1) ans = (ans + a) % p;
        b >>= 1, a = (a + a) % p;
    }
    return ans;
}

int main() {
    int k;
    ll m = 1;
    cin >> k;
    for (int i = 1;i <= k;i++) cin >> a[i];
    for (int i = 1;i <= k;i++) {
        cin >> b[i];
        m *= b[i];
    }
    ll ans = 0;
    for (int i = 1;i <= k;i++)
        ans += mul(mul(a[i],m / b[i],m),inv(m / b[i],b[i]),m), ans %= m;
    cout << ans << endl;
    return 0;
}