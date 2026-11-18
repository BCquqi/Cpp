#include<iostream>
#include<algorithm>
#define int long long 
using namespace std;

const int N = 1e5 + 5;
int d[N],f[N],s[N],q[N],dp[105][N];

signed main() {
    int n,m,p;
    cin >> n >> m >> p;
    for (int i = 2;i <= n;i++) {
        cin >> d[i];
        d[i] += d[i - 1];
    }
    for (int i = 1;i <= m;i++) {
        int h,t;
        cin >> h >> t;
        f[i] = t - d[h];
    }
    sort(f + 1,f + m + 1);
    for (int i = 1;i <= m;i++) s[i] = s[i - 1] + f[i], dp[1][i] = f[i] * i - s[i];
    for (int k = 2;k <= p;k++) {
        int l = 0,r = 0;
        q[0] = 0;
        for (int i = 1;i <= m;i++) {
            while (l < r && (dp[k - 1][q[l + 1]] + s[q[l + 1]] - dp[k - 1][q[l]] - s[q[l]]) <= f[i] * (q[l + 1] - q[l])) ++l;
            dp[k][i] = dp[k - 1][q[l]] + f[i] * (i - q[l]) - (s[i] - s[q[l]]);
            while (l < r && (dp[k - 1][i] + s[i] - dp[k - 1][q[r]] - s[q[r]]) * (q[r] - q[r - 1]) < (dp[k - 1][q[r]] + s[q[r]] - dp[k - 1][q[r - 1]] - s[q[r - 1]]) * (i - q[r])) --r;
            q[++r] = i;
        }
    }
    cout << dp[p][m] << endl;
    return 0;
}