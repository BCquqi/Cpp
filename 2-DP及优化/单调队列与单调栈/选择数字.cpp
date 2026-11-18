#include<iostream>
#include<algorithm>
#include<deque>
#define int long long
using namespace std;

const int N = 1e5 + 5;
int a[N],dp[N];
deque<int> q;

signed main() {
    int n,k,sum = 0;
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        sum += a[i];
    }
    q.push_back(0); // 初始值有对应的队列修改必须改
    for (int i = 1;i <= n;i++) {
        if (!q.empty()) dp[i] = dp[q.front()] + a[i];
        while (!q.empty() && q.front() + k < i) q.pop_front();
        while (!q.empty() && dp[q.back()] >= dp[i]) q.pop_back();
        q.push_back(i);
    }
    int ans = 1e18;
    for (int i = n - k;i <= n;i++) ans = min(ans,dp[i]);
    cout << sum - ans << endl;
    return 0;
}