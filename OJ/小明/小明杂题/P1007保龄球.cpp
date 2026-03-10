#include<iostream>
using namespace std;

const int N = 355;
int a[N][N],dp[N][N];

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= i;j++) cin >> a[i][j];
    for (int j = 1;j <= n;j++) dp[n][j] = a[n][j];
    for (int i = n - 1;i >= 1;i--)
        for (int j = 1;j <= i;j++)
            dp[i][j] = max(dp[i + 1][j + 1],dp[i + 1][j]) + a[i][j];
    cout << dp[1][1] << endl;
    return 0;
}