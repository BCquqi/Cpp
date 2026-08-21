#include<iostream>
using namespace std;

const int N = 2005;
char a[N][N];
int b[N][N],dp[N][N];

int main() {
    int h,w;
    cin >> h >> w;
    for (int i = 1;i <= h;i++)
        for (int j = 1;j <= w;j++) {
            cin >> a[i][j];
            b[i][j] = (a[i][j] == '+' ? 1 : -1);
        }
    for (int i = h - 1;i >= 1;i--) dp[i][w] = b[i - 1][w] - dp[i + 1][w];
    for (int i = w - 1;i >= 1;i--) dp[h][i] = b[h][i - 1] - dp[h][i + 1];
    for (int i = h - 1;i >= 1;i--)
        for (int j = w - 1;j >= 1;j--)
            dp[i][j] = max(b[i + 1][j] - dp[i + 1][j],b[i][j + 1] - dp[i][j + 1]);
    if (dp[1][1] > 0) cout << "Takahashi" << endl;
    else if (dp[1][1] < 0) cout << "Aoki" << endl;
    else cout << "Draw" << endl;
    return 0;
}