#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N = 1e5 + 5,M = 25;
int a[N],cnt[N],dp[N][M];
int n,k;
int L = 1,R = 0,cur = 0;

void change(int l,int r) {
    while (L > l) L--,cur += cnt[a[L]],cnt[a[L]]++;
    while (R < r) R++,cur += cnt[a[R]],cnt[a[R]]++;
    while (L < l) cnt[a[L]]--,cur -= cnt[a[L]],L++;
    while (R > r) cnt[a[R]]--,cur -= cnt[a[R]],R--;
    return ;
}

void solve(int j,int l,int r,int pl,int pr) {
    if (l > r) return ;
    int mid = (l + r) >> 1;
    int pos = pl;
    int res = 1e18;
    for (int t = pl;t <= min(mid - 1,pr);t++) {
        change(t + 1,mid);
        int val = dp[t][j - 1] + cur;
        if (val < res) res = val,pos = t;
    }
    dp[mid][j] = res;
    solve(j,l,mid - 1,pl,pos);
    solve(j,mid + 1,r,pos,pr);
    return ;
}

signed main() {
    cin >> n >> k;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 0;i <= n;i++)
        for (int j = 0;j <= k;j++)
            dp[i][j] = 1e18;
    dp[0][0] = 0;
    for (int j = 1;j <= k;j++) solve(j,1,n,0,n - 1);
    cout << dp[n][k] << endl;
    return 0;
}