#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
ll a[N],b[N];

inline ll lcm(ll x,ll y) {return x / __gcd(x,y) * y;};

ll exgcd(ll a,ll b,ll &x,ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b,a % b,x,y),t = x;
    x = y, y = (t - a / b * y);
    return d;
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

ll solve(ll m1,ll m2,ll c) {
    ll x,y;
    ll d = exgcd(m1,m2,x,y);
    ll mod = m2 / d;
    return (mul(x,c / d,mod) + mod) % mod;
}

ll excrt(int n,ll a[],ll m[]) {
    ll M = 1,x = 0;
    for (int i = 1;i <= n;i++) {
        ll t = lcm(M,m[i]);
        ll q = solve(M,m[i],a[i] - x);
        x = (x + mul(M,q,t)) % t;
        M = t;
    }
    return x;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i] >> b[i];
    cout << excrt(n,b,a) << endl;
    return 0;
}