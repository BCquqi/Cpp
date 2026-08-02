#include<iostream>
using namespace std;

const int N = 5005;
int x[N],y[N],z[N],a[N],cnt[N];

int main() {
    int n,m,k,t;
    cin >> n >> m >> k >> t;
    for (int i = 1;i <= m;i++) cin >> x[i] >> y[i] >> z[i];
    for (int i = 1;i <= k;i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 0;i < (1 << n);i++) {
        for (int j = 1;j <= n;j++) {
            if ((i >> j) & 1) dp[i][j] = max(dp[i][j],dp[i ^ (1 << j)] + dis)
        }
    }
    return 0;
}