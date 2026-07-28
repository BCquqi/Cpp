#include<iostream>
#include<cmath>
using namespace std;

const int N = 1e4 + 5,M = 5,mod = 1e6;
int a[N][M],n,m,K,p[300],cnt = 0,T = 0;
long long dp[N][300],ans = 0;
// dp[i][j] 表示前 i 层，第 i 层状态为 j 的合法方案数

bool check(int x) {
    int last = 4;
    for (int i = 1;i <= m;i++) {
        if (x % 3 == last) return false;
        last = x % 3,x /= 3;
    }
    return true;
}

bool and3(int x,int y) {
    for (int i = 1;i <= m;i++) {
        if (x % 3 == y % 3) return false;
        x /= 3,y /= 3;
    }
    return true;
}

int main() {
    cin >> n >> m >> K;
    for (int i = 1;i <= m;i++) {
        cin >> a[K][i];
        T = T * 3 + a[K][i] - 1;
    }
    for (int i = 0;i < pow(3,m);i++)
        if (check(i)) p[++cnt] = i;
    for (int i = 1;i <= cnt;i++) dp[1][i] = 1;
    for (int i = 2;i <= K;i++)
        for (int j = 1;j <= cnt;j++)
            for (int k = 1;k <= cnt;k++)
                if (and3(p[j],p[k]))
                    dp[i][j] += dp[i - 1][k],dp[i][j] %= mod;
    for (int i = 1;i <= cnt;i++)
        if (p[i] != T) dp[K][i] = 0;
    for (int i = K + 1;i <= n;i++)
        for (int j = 1;j <= cnt;j++)
            for (int k = 1;k <= cnt;k++)
                if (and3(p[j],p[k]))
                    dp[i][j] += dp[i - 1][k],dp[i][j] %= mod;
    for (int i = 1;i <= cnt;i++) ans += dp[n][i],ans %= mod;
    cout << ans << endl;
    return 0;
}