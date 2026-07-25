#include<iostream>
using namespace std;

const int N = 1e5 + 5;
int a[N],dp[32];

int main() {
    int n,maxn = 0;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++) {
        maxn = 0;
        for (int k = 0;k <= 30;k++)
            if (a[i] & (1 << k)) maxn = max(maxn,dp[k] + 1);
        for (int k = 0;k <= 30;k++)
            if (a[i] & (1 << k)) dp[k] = maxn;
    }
    int ans = 0;
    for (int i = 0;i <= 30;i++) ans = max(ans,dp[i]);
    cout << ans << endl;
    return 0;
}