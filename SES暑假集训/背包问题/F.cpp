#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e7 + 5;
long long dp[N],w[3];

void solve() {
    int n;
    cin >> n >> w[1] >> w[2] >> w[3];
    memset(dp,-1,sizeof dp);
    dp[0] = 0;
    for (int i = 1;i <= 3;i++)
        for (int j = w[i];j <= n;j++)
            if (dp[j - w[i]] != -1) dp[j] = max(dp[j],dp[j - w[i]] + 1);
    cout << dp[n] << endl;
    return ;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}