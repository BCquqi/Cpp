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
    int n;
    ll m = 1;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i] >> b[i];
        m *= a[i];
    }
    ll ans = 0;
    for (int i = 1;i <= n;i++)
        ans += mul(mul(b[i],m / a[i],m),inv(m / a[i],a[i]),m), ans %= m;
    cout << ans << endl;
    return 0;
}