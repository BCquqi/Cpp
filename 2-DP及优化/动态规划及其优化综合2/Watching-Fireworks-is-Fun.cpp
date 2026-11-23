#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;

const int N = 305,M = 1.5e5 + 5;
int a[N],b[N],t[N];
long long dp[2][M];

/*
朴素: 
dp[i][j] 表示在处理第 i 个烟花，当前处于位置 j 的最大幸福值
则对于 dp[i][j]，遍历 j - d -- j + d 区间，处理最大值。
优化: 
用单调队列维护 dp[i][j - k] 的最大值。
*/

deque<int> q;

int main() {
    int n,m,d;
    cin >> n >> m >> d;
    for (int i = 1;i <= m;i++) cin >> a[i] >> b[i] >> t[i];
    memset(dp,-0x3f,sizeof dp);
    for (int j = 1;j <= n;j++) dp[1][j] = b[1] - abs(a[1] - j);
    for (int i = 2;i <= m;i++) {
        memset(dp[i & 1],-0x3f,sizeof dp[i & 1]);
        // 有效维护区间: j - d to j + d
        // 为了方便维护，跑两遍
        q.clear();
        for (int j = 1;j <= n;j++) {
            while (!q.empty() && q.front() + 1ll * (t[i] - t[i - 1]) * d < j) q.pop_front();
            while (!q.empty() && dp[i - 1 & 1][q.back()] < dp[i - 1 & 1][j]) q.pop_back();
            q.push_back(j);
            dp[i & 1][j] = max(dp[i & 1][j],dp[i - 1 & 1][q.front()] + b[i] - abs(a[i] - j));
        }
        q.clear();
        for (int j = n;j >= 1;j--) {
            while (!q.empty() && q.front() - 1ll * (t[i] - t[i - 1]) * d > j) q.pop_front();
            while (!q.empty() && dp[i - 1 & 1][q.back()] < dp[i - 1 & 1][j]) q.pop_back();
            q.push_back(j);
            dp[i & 1][j] = max(dp[i & 1][j],dp[i - 1 & 1][q.front()] + b[i] - abs(a[i] - j));
        }
    }
    long long ans = -1e18;
    for (int j = 1;j <= n;j++) ans = max(ans,dp[m & 1][j]);
    cout << ans << endl;
    return 0;
}