#include<iostream>
using namespace std;

const int N = 3e4 + 2005,M = 65;
int v[M][3],w[M][3],dp[M][N];

int main() {
    int n,m,cur = 0;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int V,P,Q;
        cin >> V >> P >> Q;
        if (Q == 0) v[i][0] = P,w[i][0] = V;
        else if (v[Q][1] == 0) // 还没有附件
            v[Q][1] = P,w[Q][1] = V;
        else // 有过 1 个附件了
            v[Q][2] = P,w[Q][2] = V;
    }
    for (int i = 1;i <= m;i++)
        for (int j = 0;j <= n;j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i][0]) dp[i][j] = max(dp[i][j],dp[i - 1][j - w[i][0]] + w[i][0] * v[i][0]);
            if (j >= w[i][0] + w[i][1]) dp[i][j] = max(dp[i][j],dp[i - 1][j - w[i][0] - w[i][1]] + w[i][0] * v[i][0] + w[i][1] * v[i][1]);
            if (j >= w[i][0] + w[i][1] + w[i][2]) dp[i][j] = max(dp[i][j],dp[i - 1][j - w[i][0] - w[i][1] - w[i][2]] + w[i][0] * v[i][0] + w[i][1] * v[i][1] + w[i][2] * v[i][2]);
        }
    cout << dp[m][n] << endl;
    return 0;
}