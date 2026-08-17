#include<iostream>
#include<cstring>
using namespace std;

const int N = 105,M = 10005;
int p[N][N],dp[M];

int main() {
    freopen("souvenir.in","r",stdin); // 还真要写文件读写啊。。。
    freopen("souvenir.out","w",stdout);
    int t,n,m;
    cin >> t >> n >> m;
    for (int i = 1;i <= t;i++)
        for (int j = 1;j <= n;j++) cin >> p[i][j];
    for (int i = 1;i < t;i++) {
        memset(dp,0,sizeof dp);
        for (int j = 1;j <= n;j++)
            for (int k = 0;k <= m;k++)
                if (k >= p[i][j])
                    dp[k] = max(dp[k],dp[k - p[i][j]] + p[i + 1][j] - p[i][j]);
        m += dp[m];
    }
    cout << m << endl;
    return 0;
}