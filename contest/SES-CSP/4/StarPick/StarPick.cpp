#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N = 20,M = 230;
int v[M];
long long dp[M][4],f[M][4];
struct Node {int x,y,val;} a[M];

// dp[i][1/2/3] 表示：已经选了 1/2/3 个，上一个选的是 i 的最大收益
// f[i][1/2/3] 表示：已经选了 1/2/3 个，乙预留给甲的门槛是 v[k] 的最大收益

int main() {
    freopen("StarPick.in","r",stdin);
    freopen("StarPick.out","w",stdout);
    int n,cur = 0;
    cin >> n;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++) {
            int x;
            cin >> x;
            if (x) a[++cur] = {i,j,x},v[cur] = x;
        }
    sort(v + 1,v + cur + 1);
    int m = unique(v + 1,v + cur + 1) - v - 1;
    for (int k = 1;k <= m;k++) { // 预留给甲的门槛
        long long mx1 = 0,mx2 = 0,mx3 = 0;
        for (int i = 1;i <= cur;i++) { // 选择的个数
            if (a[i].val >= v[k]) continue;
            dp[i][1] = a[i].val;
            dp[i][2] = dp[i][3] = -1e18;
            for (int j = 1;j < i;j++) { // 上一个是谁
                if (a[j].val >= v[k]) continue;
                if (a[j].y > a[i].y) continue;
                dp[i][2] = max(dp[i][2],dp[j][1] + a[i].val);
                dp[i][3] = max(dp[i][3],dp[j][2] + a[i].val);
            }
            mx1 = max(mx1,dp[i][1]);
            mx2 = max(mx2,dp[i][2]);
            mx3 = max(mx3,dp[i][3]);
        }
        f[k][1] = mx1;
        f[k][2] = max(mx2,f[k][1]);
        f[k][3] = max(mx3,f[k][2]);
    }
    long long ans = 0;
    for (int i = 1;i <= cur;i++)
        ans = max(ans,f[lower_bound(v + 1,v + m + 1,a[i].val) - v][1] + a[i].val);
    for (int i = 1;i <= cur;i++)
        for (int j = i + 1;j <= cur;j++) {
            if (a[i].y > a[j].y) continue;
            ans = max(ans,f[lower_bound(v + 1,v + m + 1,min(a[i].val,a[j].val)) - v][2] + a[i].val + a[j].val);
        }
    for (int i = 1;i <= cur;i++)
        for (int j = i + 1;j <= cur;j++) {
            if (a[i].y > a[j].y) continue;
            for (int k = j + 1;k <= cur;k++) {
                if (a[j].y > a[k].y) continue;
                ans = max(ans,f[lower_bound(v + 1,v + m + 1,min(a[i].val,min(a[j].val,a[k].val))) - v][3] + a[i].val + a[j].val + a[k].val);
            }
        }
    cout << ans << endl;
    return 0;
}