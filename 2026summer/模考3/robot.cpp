#include<iostream>
#include<cstdio>
using namespace std;

const int N = 1e7 + 5;
int a[N];
long long s[N],dp[N];

int main() {
    freopen("robot.in","r",stdin);
    freopen("robot.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,k;
    long long ans = 0;
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for (int i = n;i >= 1;i--) {
        int l = i,r = n,mid,j = n + 1;
        while (l <= r) {
            mid = l + r >> 1;
            if (s[mid] - s[i - 1] <= k) l = mid + 1;
            else r = mid - 1,j = mid;
        }
        if (j == n + 1) dp[i] = n - i + 1;
        else dp[i] = dp[j + 1] + j - i;
    }
    for (int i = 1;i <= n;i++) ans += dp[i];
    cout << ans << endl;
    return 0;
}