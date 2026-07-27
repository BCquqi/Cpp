#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 17;
int s[N];
long long dp[1 << N][N];

// 状态 i 时，最后一个加入的是第 j 位的方案数

int main() {
    int n,k;
    long long ans = 0;
    cin >> n >> k;
    for (int i = 0;i < n;i++) cin >> s[i];
    for (int i = 0;i < n;i++) dp[1 << i][i] = 1;
    for (int i = 0;i <= (1 << n) - 1;i++)
        for (int j = 0;j < n;j++) {
            if ((i >> j) & 1 == 0) continue;
            for (int p = 0;p < n;p++)
                if ((i >> p) & 1 && abs(s[j] - s[p]) > k)
                    dp[i][j] += dp[i ^ (1 << j)][p];
        }
    for (int j = 0;j < n;j++) ans += dp[(1 << n) - 1][j];
    cout << ans << endl;
    return 0;
}