#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N = 1e7 + 5;
int mu[N],p[N],f[N],sum[N],cnt;
bool vis[N];

void init(int n) {
    mu[1] = 1;
    for (int i = 2;i <= n;i++) {
        if (!vis[i])
            p[++cnt] = i, mu[i] = -1;
        for (int j = 1;j <= cnt && i * p[j] <= n;j++) {
            vis[i * p[j]] = true;
            if (i % p[j] == 0) {
                mu[i * p[j]] = 0;
                break;
            }
            mu[i * p[j]] = -mu[i];
        }
    }
    return ;
}

void solve() {
    int n,m;
    cin >> n >> m;
    if (n > m) swap(n,m);
    int ans = 0;
    for (int l = 1,r;l <= n;l = r + 1)
        r = min(n / (n / l),m / (m / l)), 
        ans += (sum[r] - sum[l - 1]) * (n / l) * (m / l);
    cout << ans << endl;
    return ;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    init(1e7);
    for (int i = 1;i <= cnt;i++) {
        int x = p[i];
        for (int j = 1;j * x < N;j++) f[j * x] += mu[j];
    }
    for (int i = 1;i < N;i++) sum[i] = sum[i - 1] + f[i];
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}