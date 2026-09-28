#include<iostream>
#include<vector>
#include<cstring>
#define int long long
using namespace std;

const int N = 1e5 + 5,M = 20;
int c,T,w[M][M],dp[1 << 20][M];

void solve() {
    memset(w,0,sizeof w);
    int n,m;
    cin >> n >> m;
    int C = 0;
    for (int i = 1;i <= n;i++) {
        string a;
        cin >> a;
        vector<int> tmp;
        for (int j = 0;j < m;j++) {
            C += (a[j] == '1');
            if (a[j] == '1') tmp.push_back(j);
        }
        for (int j = 0;j < tmp.size();j++)
            for (int k = j + 1;k < tmp.size();k++)
                w[tmp[j]][tmp[k]]++, w[tmp[k]][tmp[j]]++;
    }
    memset(dp,-1,sizeof dp);
    for (int i = 0;i < m;i++) dp[1 << i][i] = 0;
    for (int s = 1;s < (1 << m);s++)
        for (int v = 0;v < m;v++) {
            if (dp[s][v] == -1) continue;
            for (int u = 0; u < m; ++u)
                if (!(s & (1 << u))) {
                    int S = s | (1 << u);
                    dp[S][u] = max(dp[S][u],dp[s][v] + w[u][v]);
                }
        }
    int maxn = 0;
    for (int i = 0;i < m;i++)
        maxn = max(maxn,dp[(1 << m) - 1][i]);
    cout << C - maxn << endl;
    return ;
}

signed main() {
    freopen("sheet.in","r",stdin);
    freopen("sheet.out","w",stdout);
    cin >> c >> T;
    while (T--) solve();
    return 0;
}