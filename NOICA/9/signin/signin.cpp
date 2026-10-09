#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2005,mod = 1e9 + 7;
long long a[N],c[N],pre[N],suf[N];

void solve() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= m;i++) cin >> c[i];
    sort(c + 1,c + m + 1);
    long long mul = 1;
    for (int i = 1;i <= m;i++) mul = mul * c[i] % mod;
    pre[0] = 1;
    for (int i = 1;i <= n;i++) pre[i] = pre[i - 1] * a[i] % mod;
    suf[n + 1] = 1;
    for (int i = n;i >= 1;i--) suf[i] = suf[i + 1] * a[i] % mod;
    long long sum = 0;
    for (int i = 1;i <= n;i++) {
        int pos = lower_bound(c + 1, c + m + 1, a[i]) - c;
        if (!(pos <= m && c[pos] == a[i])) 
            sum = (sum + pre[i - 1] * suf[i + 1] % mod) % mod;
    }
    if (sum == mul) cout << "Y" << endl;
    else cout << "N" << endl;
}

int main() {
    freopen("signin.in","r",stdin);
    freopen("signin.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}