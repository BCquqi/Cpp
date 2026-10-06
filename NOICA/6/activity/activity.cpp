#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N = 1e5 + 5,mod = 998244353;
int dp[N],s[N];

signed main() {
    freopen("activity.in","r",stdin);
    freopen("activity.out","w",stdout);
    int n,x,y;
    cin >> n >> x >> y;
    dp[0] = s[0] = 1;
    for (int i = 1;i <= x;i++) { // 当前总质量
        int left = i - min(n,i),right = i - (i + 1) / 2; // 求前缀和
        if (left == 0) dp[i] += s[right];
        else dp[i] += s[right] - s[left - 1];
        if (left <= i - y && i - y <= right) dp[i] -= dp[i - y];
        dp[i] %= mod;
        s[i] = s[i - 1] + dp[i], s[i] %= mod;
    }
    cout << dp[x] << endl;
    return 0;
}