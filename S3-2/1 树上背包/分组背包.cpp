#include<iostream>
#include<algorithm>
using namespace std;

const int N = 105;
int s[N],w[N][N],v[N][N],dp[N][N];

int main() {
    int n,W;
    cin >> n >> W;
    for (int i = 1;i <= n;i++) {
        cin >> s[i];
        for (int j = 1;j <= s[i];j++)
            cin >> w[i][j] >> v[i][j];
    }
    for (int i = 1;i <= n;i++)
        for (int j = 0;j <= W;j++) {
            dp[i][j] = dp[i - 1][j];
            for (int k = 1;k <= s[i];k++)
                if (j >= w[i][k]) dp[i][j] = max(dp[i][j],dp[i - 1][j - w[i][k]] + v[i][k]);
        }
    cout << dp[n][W] << endl;
    return 0;
}