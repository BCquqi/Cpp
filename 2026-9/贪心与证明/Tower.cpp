#include<iostream>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;

const int N = 1e3 + 5,M = 2e4 + 5;
struct Node {int w,s,v;} a[N];
int dp[M];

signed main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++)
        cin >> a[i].w >> a[i].s >> a[i].v;
    sort(a + 1,a + n + 1,[](Node x,Node y) {return x.s + x.w < y.s + y.w;});
    for (int i = 1;i <= n;i++)
        for (int j = a[i].s + a[i].w;j >= a[i].w;j--)
            dp[j] = max(dp[j],dp[j - a[i].w] + a[i].v);
    int ans = 0;
    for (int i = 0;i <= 20000;i++) ans = max(ans,dp[i]);
    cout << ans << endl;
    return 0;
}