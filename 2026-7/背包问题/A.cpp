#include<iostream>
using namespace std;

const int N = 105,M = 1005;
int w[N],v[N],dp[N][M];

int main() {
    int t,m;
    cin >> t >> m;
    for (int i = 1;i <= m;i++) cin >> w[i] >> v[i];
    for (int i = 1;i <= m;i++)
        for (int j = 0;j <= t;j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i]) dp[i][j] = max(dp[i][j],dp[i - 1][j - w[i]] + v[i]);
        }
    cout << dp[m][t] << endl;
    return 0;
}