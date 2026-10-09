#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N = 2005, mod1 = 1e9 + 7, mod2 = 1e9 + 9;

struct Hash {
    int h1, h2;
    Hash operator + (const Hash &x) const { return {(h1 + x.h1) % mod1, (h2 + x.h2) % mod2}; }
    bool operator == (const Hash &x) const { return h1 == x.h1 && h2 == x.h2; }
} target, sum, pre[N], suf[N], b[N];

int a[N], c[N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> c[i];
    
    sort(c + 1, c + m + 1);

    target.h1 = target.h2 = 1;
    for (int i = 1; i <= m; i++) {
        target.h1 = target.h1 * c[i] % mod1;
        target.h2 = target.h2 * c[i] % mod2;
    }

    pre[0].h1 = pre[0].h2 = 1;
    for (int i = 1; i <= n; i++) {
        pre[i].h1 = pre[i - 1].h1 * a[i] % mod1;
        pre[i].h2 = pre[i - 1].h2 * a[i] % mod2;
    }
    
    suf[n + 1].h1 = suf[n + 1].h2 = 1;
    for (int i = n; i >= 1; i--) {
        suf[i].h1 = suf[i + 1].h1 * a[i] % mod1;
        suf[i].h2 = suf[i + 1].h2 * a[i] % mod2;
    }

    for (int i = 1; i <= n; i++) {
        b[i].h1 = pre[i - 1].h1 * suf[i + 1].h1 % mod1;
        b[i].h2 = pre[i - 1].h2 * suf[i + 1].h2 % mod2;
    }

    sum.h1 = sum.h2 = 0;
    for (int i = 1; i <= n; i++) {
        if (!binary_search(c + 1, c + m + 1, a[i])) {
            sum = sum + b[i];
        }
    }

    if (sum == target) cout << "Y\n";
    else cout << "N\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}