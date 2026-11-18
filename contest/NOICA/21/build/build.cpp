#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 3002,mod = 20091023;
int n,K;
int a[N],dp[N][N];
int v[N],c[N];
int C[N][N],fac[N];

void init() {
    for (int i = 0;i <= n;i++) C[i][0] = C[i][i] = 1;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j < i;j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    fac[0] = 1;
    for (int i = 1;i <= n;i++) fac[i] = 1ll * fac[i - 1] * i % mod;
    return ;
}

int main() {
    freopen("build.in","r",stdin);
    freopen("build.out","w",stdout);
    cin >> n >> K;
    for (int i = 1;i <= n;i++) cin >> a[i];
    init();
    sort(a + 1,a + 1 + n);
    int cur = 0;
    for (int i = 1;i <= n;i++) {
        if (a[i] != a[i - 1]) v[++cur] = a[i];
        c[cur]++;
    }
    memset(dp,0,sizeof dp);
    int s = 0;
    dp[0][0] = 1;
    for (int i = 1;i <= cur;i++) {
        for (int j = 0;j <= s;j++)
            for (int k = 0;k <= c[i] && k <= j;k++)
                dp[i][j] = (dp[i][j] + 1ll * dp[i - 1][j - k] * C[s - j + k][k] % mod * C[c[i] + j - k][c[i] - k] % mod * fac[c[i]] % mod) % mod;
        s += c[i];
    }
    cout << dp[cur][K] << endl;
    return 0;
}