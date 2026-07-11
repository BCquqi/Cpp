#include<iostream>
using namespace std;

const int N = 45,M = 1005;
long long dp[N][M]; // dp[i][j] 表示选到第 i 个数后，选进第一组的数字和为 j 的方法数

int main() {
    int n;
    cin >> n;
    int sum = n * (n + 1) / 2;
    if (sum % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }
    dp[0][0] = 1;
    for (int i = 1;i <= n;i++) {
        for (int j = 0;j <= i * (i + 1) / 2;j++) { // 这一步的数字和
            dp[i][j] = dp[i - 1][j];
            if (j >= i) dp[i][j] += dp[i - 1][j - i];
        }
    }
    cout << dp[n][sum / 2] / 2 << endl;
    return 0;
}