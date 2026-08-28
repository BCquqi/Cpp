#include<iostream>
using namespace std;

const int N = 5e6 + 5;
int a[N],f[N],g[N],inv[N];

long long qpow(long long a,long long b,long long p) {
    long long ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
}

int main() {
    int n,p,k;
    n = read(), p = read(), k = read();
    for (int i = 1;i <= n;i++) a[i] = read();
    int tmp = 1,ans = 0;
    f[0] = 1;
    for (int i = 1;i <= n;i++)
        f[i] = 1ll * f[i - 1] * a[i] % p;
    g[n] = qpow(f[n],p - 2,p);
    for (int i = n - 1;i >= 1;i--)
        g[i] = 1ll * g[i + 1] * a[i + 1] % p;
    for (int i = 1;i <= n;i++)
        tmp = 1ll * tmp * k % p, inv[i] = 1ll * f[i - 1] * g[i] % p, ans = (1ll * ans + (1ll * tmp * inv[i]) % p) % p;
    cout << ans << '\n';
    return 0;
}