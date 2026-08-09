/*
赛后反思

本题得到暴力的50pts是不够理想的。如果T2没有浪费过多时间是绝对可以得到至少70pts的。

本题的70pts是纯更新，在此基础上参考了背包里第二维定义的思想，j的含义改成了两人差值。
*/

#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

const int N = 505,M = 1e5 + 5;
int dp[N][M],a[N];

int main() {
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    int n,sum = 0;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        sum += a[i];
    }
    memset(dp,-0x3f,sizeof dp);
    dp[0][0] = 0;
    for (int i = 1;i <= n;i++)
        for (int j = 0;j <= sum;j++) {
            dp[i][j] = dp[i - 1][j];
            dp[i][j] = max(dp[i][j],dp[i - 1][j + a[i]] + a[i]);
            dp[i][j] = max(dp[i][j],dp[i - 1][abs(j - a[i])] + a[i]);
        }
    cout << sum - dp[n][0] / 2 << endl;
    return 0;
}