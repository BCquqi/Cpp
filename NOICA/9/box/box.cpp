#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N = 55, mod = 1e9 + 7;
char a[N][N];
int n,m,C[N][N],x[N],y[N];

signed main() {
    freopen("box.in","r",stdin);
    freopen("box.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
        for (int j = 1; j <= m;j++)
            cin >> a[i][j];
    for (int i = 0;i <= 50;i++) {
        C[i][0] = 1;
        for (int j = 1;j <= i;j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            if (a[i][j] == '#') x[i]++;
    for (int j = 1;j <= m;j++)
        for (int i = 1;i <= n;i++)
            if (a[i][j] == '#') y[j]++;
    bool flag1 = true,flag2 = true;
    for (int j = 1;j <= m;j++)
        for (int i = y[j] + 1;i <= n;i++)
            if (a[i][j] == '#') flag1 = false;
    flag2 = flag1;
    for (int i = 1;i <= n;i++)
        for (int j = x[i] + 1;j <= m;j++)
            if (a[i][j] == '#') flag2 = false;
    for (int i = 1;i <= n;i++)
        if (x[i] != 0 && x[i] != x[1]) flag2 = false;
    for (int j = 1;j <= m;j++)
        if (y[j] != 0 && y[j] != y[1]) flag2 = false;
    if (!flag1) cout << 1 << endl;
    else if (!flag2) {
        int ans = 1;
        for (int j = 1; j <= m; j++)
            ans = ans * C[n][y[j]] % mod;
        cout << ans << endl;
    } else {
        int ans1 = 1, ans2 = 1;
        for (int j = 1; j <= m; j++)
            ans1 = ans1 * C[n][y[j]] % mod;
        for (int i = 1; i <= n; i++) 
            ans2 = ans2 * C[m][x[i]] % mod;
        cout << (ans1 + ans2 - 1 + mod) % mod << endl;
    }
    return 0;
}