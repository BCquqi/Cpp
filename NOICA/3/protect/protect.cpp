#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 205,offset = 200;
double dp[2][N][3005]; // 处理了 i 个挑战 成功 j 次 背包容量 w (有偏移量) 的概率
int a[N];
double p[N];

int main() {
    freopen("protect.in","r",stdin);
    freopen("protect.out","w",stdout);
    int n,l,k;
    scanf("%d%d%d",&n,&l,&k);
    for (int i = 1;i <= n;i++) {
        scanf("%lf",&p[i]);
        p[i] /= 100.0;
    }
    for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
    dp[0][0][k + offset] = 1.0;
    for (int i = 1;i <= n;i++) { // 物品
        memset(dp[i & 1],0,sizeof dp[i & 1]);
        for (int j = 0;j <= i;j++) { // 成功几次
            for (int K = 0;K <= 2200 + offset;K++) { // 背包容量
                dp[i & 1][j][K] += dp[i - 1 & 1][j][K] * (1.0 - p[i]); // 失败
                if (j > 0) { // 成功
                    if (a[i] == -1 && K + 1 <= 2200 + offset) // 获得碎片
                        dp[i & 1][j][K] += dp[i - 1 & 1][j - 1][K + 1] * p[i];
                    else if (a[i] >= 0 && K - a[i] >= 0)
                        dp[i & 1][j][K] += dp[i - 1 & 1][j - 1][K - a[i]] * p[i];
                }
            }
        }
    }
    double ans = 0.0;
    for (int i = l;i <= n;i++)
        for (int j = offset;j <= 2200 + offset;j++)
            ans += dp[n & 1][i][j];
    printf("%.6f\n", ans);
    return 0;
}