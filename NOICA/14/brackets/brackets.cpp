#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e5 + 5;
int a[N];
bool o[N];
long long dp[N][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0); 
    freopen("brackets.in","r",stdin);
    freopen("brackets.out","w",stdout);
    int n;
    cin >> n;
    o[1] = 1;
    for (int i = 1;i <= n + n - 1;i++) {
        if (i & 1) cin >> a[(i + 1) / 2];
        else {
            char c;
            cin >> c;
            if (c == '+') o[i / 2 + 1] = 1;
            else o[i / 2 + 1] = 0;
        }
    }
    memset(dp,-0x3f,sizeof dp);
    dp[0][0] = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = 0;j <= 2;j++) {
            long long s = o[i] ? 1 : -1;
            if (j & 1) s = -s;
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i] * s);
            if (j != 2 && o[i] == 0)
                dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] + a[i] * s);
            if (j != 0)
                dp[i][j - 1] = max(dp[i][j - 1], dp[i - 1][j] + a[i] * s);
        }
    }
    cout << max(dp[n][0],max(dp[n][1],dp[n][2])) << endl;
    return 0;
}