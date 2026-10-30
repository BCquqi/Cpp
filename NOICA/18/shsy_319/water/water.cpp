#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main() {
    freopen("water.in","r",stdin);
    freopen("water.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n,m,T;
    cin >> n >> m >> T;
    int a[n + 5][m + 5],d[n + 5][m + 5],s[n + 5][m + 5];
    memset(d,0,sizeof d), memset(s,0,sizeof s);
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            cin >> a[i][j];
    for (int i = 1;i <= T;i++) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        d[x2 + 1][y2 + 1]++, d[x2 + 1][y1]--, d[x1][y2 + 1]--, d[x1][y1]++;
        s[x2 + 1][y2 + 1] += i, s[x2 + 1][y1] -= i, s[x1][y2 + 1] -= i, s[x1][y1] += i;
    }
    int cnt[n + 5][m + 5],sum[n + 5][m + 5],ans = 0;
    memset(cnt,0,sizeof cnt), memset(sum,0,sizeof sum);
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++) {
            cnt[i][j] = cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1] + d[i][j], 
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + s[i][j];
            if (cnt[i][j] > 1 || cnt[i][j] == 1 && sum[i][j] != a[i][j]) ans++;
        }
    cout << ans << endl;
    return 0;
}