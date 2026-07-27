#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 25,M = 1005;
int d[N],c[N],a[N][M],dp[(1 << 20) + 5];

int main() {
    int n,l,ans = 1e9;
    cin >> n >> l;
    for (int i = 1;i <= n;i++) {
        cin >> d[i] >> c[i];
        for (int j = 1;j <= c[i];j++) cin >> a[i][j];
    }
    memset(dp,-0x3f,sizeof dp);
    dp[0] = 0;
    for (int i = 0;i < (1 << n);i++) {
        int s = i,cnt = 0;
        while (s) {
            int p = s & -s;
            int j = __lg(p) + 1;
            int k = upper_bound(a[j] + 1,a[j] + c[j] + 1,dp[i ^ p]) - a[j] - 1;
            if (k > 0) dp[i] = max(dp[i],a[j][k] + d[j]);
            s -= p,cnt++;
        }
        if (dp[i] >= l) ans = min(ans,cnt);
    }
    cout << (ans == 1e9 ? -1 : ans) << endl;
    return 0;
}