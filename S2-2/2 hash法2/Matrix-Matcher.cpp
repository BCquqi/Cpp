#include<iostream>
using namespace std;

const int N = 1e3 + 5,M = 105,P = 1009,Q = 1051,mod = 1e9 + 7;
long long p[N],q[N],h[N][N],hb[M][M];
char a[N][N],b[M][M];

long long Hash(int x1,int y1,int x2,int y2) {
    long long ret = h[x2][y2] - h[x1 - 1][y2] * p[x2 - x1 + 1] % mod - h[x2][y1 - 1] * q[y2 - y1 + 1] % mod
     + h[x1 - 1][y1 - 1] * p[x2 - x1 + 1] % mod * q[y2 - y1 + 1] % mod;
     return (ret % mod + mod) % mod;
}

void solve() {
    int n,m,x,y;
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++) cin >> a[i][j];
    cin >> x >> y;
    for (int i = 1;i <= x;i++)
        for (int j = 1;j <= y;j++) cin >> b[i][j];
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            h[i][j] = ((h[i - 1][j] * P % mod + h[i][j - 1] * Q % mod - h[i - 1][j - 1] * P % mod * Q % mod + a[i][j]) % mod + mod) % mod;
    for (int i = 1;i <= x;i++)
        for (int j = 1;j <= y;j++)
            hb[i][j] = ((hb[i - 1][j] * P % mod + hb[i][j - 1] * Q % mod - hb[i - 1][j - 1] * P % mod * Q % mod + b[i][j]) % mod + mod) % mod;
    int ans = 0;
    for (int i = 1;i + x - 1 <= n;i++)
        for (int j = 1;j + y - 1 <= m;j++) {
            int hs = Hash(i,j,i + x - 1,j + y - 1);
            if (hs == hb[x][y]) ans++;
        } 
    cout << ans << endl;
    return ;
}

int main() {
    int T;
    cin >> T;
    p[0] = q[0] = 1;
    for (int i = 1;i <= N;i++) p[i] = p[i - 1] * P % mod,q[i] = q[i - 1] * Q % mod;
    while (T--) solve();
    return 0;
}