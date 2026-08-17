#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 2005;
int ap[N],bp[N],as[N],bs[N],dp[N][N];
// dp[i][j] 表示处理完第 i 天，手上现在有 j 张股票可以赚到的最大钱数

deque<int> q;

int main() {
    int t,maxp,w;
    cin >> t >> maxp >> w;
    for (int i = 1;i <= t;i++) cin >> ap[i] >> bp[i] >> as[i] >> bs[i];
    memset(dp,-0x3f,sizeof dp);
    for (int i = 1;i <= t;i++) {
        for (int j = 0;j <= as[i];j++)
            dp[i][j] = max(dp[i][j],-ap[i] * j);
        for (int j = 0;j <= maxp;j++)
            dp[i][j] = max(dp[i][j],dp[i - 1][j]);
        if (i <= w) continue;
        q.clear();
        for (int j = 0;j <= maxp;j++) {
            while (!q.empty() && q.front() + as[i] < j) q.pop_front();
            while (!q.empty() && dp[i - w - 1][q.back()] + q.back() * ap[i] <= dp[i - w - 1][j] + j * ap[i]) q.pop_back();
            q.push_back(j);
            dp[i][j] = max(dp[i][j],dp[i - w - 1][q.front()] - (j - q.front()) * ap[i]);
        }
        q.clear();
        for (int j = maxp;j >= 0;j--) {
            while (!q.empty() && q.front() - bs[i] > j) q.pop_front();
            while (!q.empty() && dp[i - w - 1][q.back()] + q.back() * bp[i] <= dp[i - w - 1][j] + j * bp[i]) q.pop_back();
            q.push_back(j);
            dp[i][j] = max(dp[i][j],dp[i - w - 1][q.front()] - (j - q.front()) * bp[i]);
        }
    }
    cout << dp[t][0] << endl;
    return 0;
}