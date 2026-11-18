#include<iostream>
#include<deque>
#include<cstring>
#define int long long
using namespace std;

const int N = 1e5 + 5;
int type[N],dp[N][2];
// dp[i][0 / 1] 表示处理到第 i 位时，是否点亮第 i 位的最小花销

deque<int> q;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("stage.in","r",stdin);
    freopen("stage.out","w",stdout);
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0;i < s.size();i++)
        type[i + 1] = s[i] - '0';
    memset(dp,0x3f,sizeof dp);
    dp[0][0] = 0;
    // 单调队列维护一个滑动窗口 [i - k, i] 中 type = 1 位置的 dp[i][1] 最小值
    for (int i = 1;i <= n;i++) {
        while (!q.empty() && q.front() + k < i) q.pop_front();
        // 必须在所有操作开始前就维护好窗口限制
        if (type[i] == 0) {
            if (!q.empty()) dp[i][0] = dp[q.front()][1]; // 选择可以照亮它的 dp 中答案最小的
            dp[i][1] = min(dp[i - 1][0],dp[i - 1][1]) + i;
        } else {
            if (!q.empty()) dp[i][0] = dp[q.front()][1]; // 不点亮时与 type = 0 同理
            if (i - k > 0) dp[i][1] = min(dp[i - k - 1][0],dp[i - k - 1][1]) + i; // i - k > 0 代表前面还有灯光覆盖不到的地方，要累加
            else dp[i][1] = i; // 直接照亮前面所有
            while (!q.empty() && dp[q.back()][1] >= dp[i][1]) q.pop_back(); // 维护滑动窗口内 dp 最小值 (下标)
            q.push_back(i);
        }
    }
    cout << min(dp[n][0],dp[n][1]) << endl;
    return 0;
}