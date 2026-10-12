#include<algorithm>
#include<cstring>
#include<iostream>
#define int long long
using namespace std;

const int N = (1 << 18) + 5,mod = 998244353;
int w[N],dis[N],up[N],down[N][20];

signed main() {
    int n,m;
    cin >> n >> m;
    for (int i = 2;i < (1 << n);i++) {
        cin >> w[i];
        dis[i] = dis[i / 2] + w[i];
    }
    for (int i = (1 << n) - 1;i >= 2;i--)
        up[i / 2] += up[i] + ((1 << (n - __lg(i))) - 1) % mod * w[i] % mod;
    memset(down,0x3f,sizeof down);
    while (m--) {
        int u,v,w;
        cin >> u >> v >> w;
        for (int p = v;p > u;p /= 2)
            for (int q = p / 2;q >= u;q /= 2)
                down[p][__lg(q)] = min(down[p][__lg(q)],w + dis[v] - dis[p] + dis[q] - dis[u]);
    }
    for (int a = 1;a < (1 << n);a++)
        for (int b = __lg(a) - 1,c = a >> 1;c >= 1;b--, c /= 2)
            for (int d = b - 1;~d;d--)
                down[a][d] = min(down[a][d],down[a][b] + down[c][d]);
    int ans = 0;
    for (int i = (1 << n) - 1;i >= 1;i--) {
        ans = (ans + up[i]) % mod;
        for (int j = __lg(i) - 1,k = i;k >= 2;j--, k /= 2)
            if (down[i][j] != 0x3f3f3f3f3f3f3f3f)
                ans = (ans + down[i][j] * (1 << (n - __lg(k))) % mod + up[k ^ 1] + ((1 << (n - __lg(k ^ 1))) - 1) * w[k ^ 1] % mod) % mod;
    }
    cout << ans << endl;
    return 0;
}