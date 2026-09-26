#include<iostream>
#define int long long
using namespace std;

const int N = 1e6 + 5;
int a[N],cnt[N],b[N],dp[N];

signed main() {
    freopen("escape.in","r",stdin);
    freopen("escape.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int maxn = 0;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        cnt[a[i]]++;
        maxn = max(maxn,a[i]);
    }
    for (int i = 1;i <= maxn;i++) b[i] = cnt[i] * i;
    dp[1] = b[1];
    for (int i = 2;i <= maxn;i++)
        dp[i] = max(dp[i - 1],dp[i - 2] + b[i]);
    cout << dp[maxn] << endl;
    return 0;
}