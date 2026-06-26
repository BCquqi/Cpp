#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e6 + 5;
char a[N];
int dp[N][2];

int main() {
    freopen("sequencea.in","r",stdin);
    freopen("sequencea.out","w",stdout);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
    memset(dp,0x3f,sizeof dp);
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1;i <= n;i++) {
        if (a[i] == 'A') {
            dp[i][0] = min(dp[i - 1][0],dp[i - 1][1] + 1);
            dp[i][1] = min(dp[i - 1][1] + 1,dp[i][0] + 1);
        } else {
            dp[i][0] = min(dp[i - 1][0] + 1,dp[i - 1][1] + 1);
            dp[i][1] = min(dp[i - 1][1],dp[i - 1][0] + 1);
        }
    }
    cout << min(dp[n][0],dp[n][1] + 1) << endl;
    return 0;
}