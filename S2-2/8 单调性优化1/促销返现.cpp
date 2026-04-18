#include<iostream>
#include<queue>
using namespace std;

const int N = 1e5 + 5;
long long a[N],dp[N],s[N];
// dp[i]: 前 i 个物品的最小价格
deque<int> q;

int main() {
    int n,c;
    cin >> n >> c;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1;i <= n;i++) {
        while (!q.empty() && q.back() < i - c + 1) q.pop_back();
        while (!q.empty() && a[q.front()] >= a[i]) q.pop_front();
        q.push_front(i);
        dp[i] = dp[i - 1] + a[i];
        if (i >= c) dp[i] = min(dp[i],dp[i - c] + s[i] - s[i - c] - a[q.back()]);
    }
    cout << dp[n] << endl;
    return 0;
}