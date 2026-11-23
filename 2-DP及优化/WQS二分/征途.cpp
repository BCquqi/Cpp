#include<iostream>
#include<cstring>
#include<deque>
#define int long long
using namespace std;

const int N = 3005;
int a[N],s[N],dp[N],cnt[N],n,m,num;

int solve(int c) {
    memset(dp,0x3f,sizeof dp);
    dp[0] = 0,cnt[0] = 0;
    deque<int> q;
    q.push_back(0);
    for (int i = 1;i <= n;i++) {
        while (q.size() >= 2) {
            int j1 = q[0],j2 = q[1];
            if (dp[j1] + s[j1] * s[j1] - 2 * s[i] * s[j1] >= dp[j2] + s[j2] * s[j2] - 2 * s[i] * s[j2])
                q.pop_front();
            else break;
        }
        dp[i] = dp[q.front()] + (s[i] - s[q.front()]) * (s[i] - s[q.front()]) + c;
        cnt[i] = cnt[q.front()] + 1;
        while (q.size() >= 2) {
            int j1 = q[q.size() - 2],j2 = q.back();
            if ((1.00 * dp[j2] + s[j2] * s[j2] - dp[j1] - s[j1] * s[j1]) / (2 * (s[j2] - s[j1])) >= (1.00 * dp[i] + s[i] * s[i] - dp[j2] - s[j2] * s[j2]) / (2 * (s[i] - s[j2]))) q.pop_back();
            else break;
        }
        q.push_back(i);
    }
    num = cnt[n];
    return dp[n];
}

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i], s[i] = s[i - 1] + a[i];
    int tot = s[n];
    int L = 0,R = 1e18,res = 0;
    while (L <= R) {
        int mid = L + R >> 1;
        solve(mid);
        if (num >= m) res = mid, L = mid + 1;
        else R = mid - 1;
    }
    int ret = solve(res);
    cout << m * (ret - res * m) - tot * tot << endl;
    return 0;
}