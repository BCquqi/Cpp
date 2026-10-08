#include<iostream>
#include<cstring>
#define int long long
using namespace std;

const int N = 1e5 + 5;
int type[N],dp[N];

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
    dp[0] = 0;
    int cur = 1;
    for (int i = 1;i <= n;i++) {
        dp[i] = dp[i - 1] + i;
        while (cur <= n && (cur < i - k || type[cur] == 0)) cur++;
        if (cur <= n && cur <= i + k)
            dp[i] = min(dp[i], cur + dp[max(0ll,cur - k - 1)]);
    }
    cout << dp[n] << endl;
    return 0;
}