/*填表法版本*/

#include<iostream>
#include<cstring>
using namespace std;

const int N = 105;
int a[N],dp[N][N]; // dp[i][j] 表示前 i 件商品，糖果数量 mod k 为 j 的最多糖果数量

int main() {
    int n,k;
    cin >> n >> k;
    memset(dp[0],-0x3f,sizeof dp[0]);
    dp[0][0] = 0;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++)
        for (int j = 0;j < k;j++)
            dp[i][j] = max(dp[i - 1][j],dp[i - 1][((j - a[i]) % k + k) % k] + a[i]); // 选的话模后的结果必为正
    cout << dp[n][0] << endl;
    return 0;
}

/*刷表法版本*/

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 105;
int a[N],dp[N][N]; // dp[i][j] 表示前 i 件商品，糖果数量 mod k 为 j 的最多糖果数量

int main() {
    int n,k;
    cin >> n >> k;
    memset(dp[1],-0x3f,sizeof dp[1]);
    dp[1][0] = 0;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++) {
        memset(dp[i + 1],-0x3f,sizeof dp[i + 1]);
        for (int j = 0;j < k;j++)
            dp[i + 1][j] = max(dp[i + 1][j],dp[i][j]), 
            dp[i + 1][(j + a[i]) % k] = max(dp[i + 1][(j + a[i]) % k],dp[i][j] + a[i]);
    }
    cout << dp[n + 1][0] << endl;
    return 0;
}