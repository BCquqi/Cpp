#include<iostream>
#include<cstring>
using namespace std;

const int N = 5e5 + 5;
int a[N],s[N],dp[N],last[(1 << 20) + 5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n,k;
    cin >> n >> k;
    for (int i = 1;i <= n;i++) cin >> a[i], s[i] = s[i - 1] ^ a[i];
    int ans = 0;
    memset(last,-1,sizeof last);
    last[0] = 0;
    for (int i = 1;i <= n;i++)
        dp[i] = max(dp[i - 1],last[s[i] ^ k] + 1), last[s[i]] = dp[i], ans = max(ans,dp[i]);
    cout << ans << endl;
    return 0;
}