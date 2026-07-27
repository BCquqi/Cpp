#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 17;
int t[N],w[N],sum[(1 << N)],maxt[(1 << N)];
long long dp[(1 << N)];

int main() {
    int W,n;
    cin >> W >> n;
    for (int i = 0;i < n;i++) cin >> t[i] >> w[i];
    for (int i = 1;i < (1 << n);i++) {
        int j = i & -i;
        j = __lg(j);
        sum[i] = sum[i ^ (1 << j)] + w[j];
        maxt[i] = max(maxt[i ^ (1 << j)],t[j]);
    }
    memset(dp,0x3f,sizeof dp);
    dp[0] = 0;
    for (int i = 0;i < (1 << n);i++) {
        for (int j = i;j;j = i & (j - 1))
            if (sum[j] <= W) dp[i] = min(dp[i],dp[i ^ j] + maxt[j]);
    }
    cout << dp[(1 << n) - 1] << endl;
    return 0;
}