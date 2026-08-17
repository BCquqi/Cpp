#include<iostream>
using namespace std;

const int mod = 998244353;

int main() {
    freopen("square.in","r",stdin);
    freopen("square.out","w",stdout);
    long long n,ans = 0;
    cin >> n;
    for (long long i = 1;i * i <= n;i++)
        ans += (n - i * i + 1) % mod * i % mod * i % mod, ans %= mod;
    cout << ans << endl;
    return 0;
}