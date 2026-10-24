#include<iostream>
#include<algorithm>
#include<cstdio>
#define int long long
using namespace std;

const int N = 3e5 + 5,mod = 100000;
int f2[N],f5[N],fr[N],ifr[N];

int qpow(int a,int b,int p) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

void exgcd(int a,int b,int &x,int &y) {
    if (b == 0) {
        x = 1, y = 0;
        return ;
    }
    exgcd(b,a % b,x,y);
    int z = x; x = y, y = z - y * (a / b);
}

int inv(int a,int p) {
    int x,y;
    exgcd(a,p,x,y);
    return (x % p + p) % p;
}

void init() {
    f2[0] = f5[0] = 0;
    fr[0] = 1;
    for (int i = 1;i < N;i++) {
        int tmp = i,c2 = 0,c5 = 0;
        while (!(tmp & 1)) c2++, tmp /= 2;
        while (tmp % 5 == 0) c5++, tmp /= 5;
        f2[i] = f2[i - 1] + c2, f5[i] = f5[i - 1] + c5, fr[i] = fr[i - 1] * tmp % mod;
    }
    for (int i = 0;i < N;i++) ifr[i] = inv(fr[i],mod);
}

int calc(int n,int r) {
    if (n < 0 || r < 0 || r > n) return 0;
    int e2 = 0,e5 = 0,res = 1;
    for (int i = 1;i <= r;i++) {
        int num = n - i + 1, den = i;
        while (!(num & 1)) e2++, num /= 2;
        while (num % 5 == 0) e5++, num /= 5;
        while (!(den & 1)) e2--, den /= 2;
        while (den % 5 == 0) e5--, den /= 5;
        res = res * (num % mod) % mod, res = res * inv(den % mod,mod) % mod;
    }
    res = res * qpow(2,e2,mod) % mod, res = res * qpow(5,e5,mod) % mod;
    return res;
}

int C(int n,int r) {
    if (n < 0 || r < 0 || r > n) return 0;
    if (n < N) {
        int e2 = f2[n] - f2[r] - f2[n - r];
        int e5 = f5[n] - f5[r] - f5[n - r];
        int res = qpow(2,e2,mod) * qpow(5,e5,mod) % mod;
        res = res * fr[n] % mod * ifr[r] % mod * ifr[n - r] % mod;
        return res;
    }
    else return calc(n,r);
}

signed main() {
    freopen("fruit.in","r",stdin);
    freopen("fruit.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    init();
    int n,k;
    cin >> n >> k;
    for (int i = 0;i < n;i++) {
        int a,b;
        int m;
        cin >> a >> b >> m;
        if (a == 0 && b == 0) {
            if (m == 0) cout << 1 << endl;
            else cout << "empty" << endl;
            continue;
        }
        if (k <= 1 && b > 0) {
            cout << "empty" << endl;
            continue;
        }
        int r = m - a * (k + 1) - b;
        if (r < 0) {
            cout << "empty" << endl;
            continue;
        }
        int ans = 0,lim = (k <= 1 || b == 0) ? 0 : r / (k - 1);
        int limit = min(b,lim);
        for (int j = 0;j <= limit;j++) {
            int tmp = C(b,j) * C(r - j * (k - 1) + a + b - 1,a + b - 1) % mod;
            if (j & 1) ans = (ans - tmp + mod) % mod;
            else ans = (ans + tmp) % mod;
        }
        if (ans == 0) cout << "empty" << endl;
        else cout << ans << endl;
    }
    return 0;
}