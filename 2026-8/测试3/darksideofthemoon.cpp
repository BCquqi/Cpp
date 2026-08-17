#include<iostream>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;

const int N = 125;
int dp[N][N];

int calc(int t,int x,int y) {
    memset(dp,0,sizeof dp);
    dp[0][0] = t - x - y + 1;
    for (int i = 0;i <= x;i++)
        for (int j = 0;j <= y;j++)
            dp[i][j + 1] += (dp[i][j] + 1) / 2, dp[i + 1][j] += dp[i][j] / 2;
    return dp[x][y];
}

signed main() {
    freopen("darksideofthemoon.in","r",stdin);
    freopen("darksideofthemoon.out","w",stdout);
    int q;
    cin >> q;
    while (q--) {
        int t,x,y;
        cin >> t >> x >> y;
        if (calc(t,x,y) != calc(t - 1,x,y)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}