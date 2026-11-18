#include<iostream>
#include<cstring>
using namespace std;

const int N = 5e4 + 5000 + 5;
int p[N],c[N],dp[N]; // 开销才是收获，代价是干草

int main() {
    int n,h;
    cin >> n >> h;
    for (int i = 1;i <= n;i++) cin >> p[i] >> c[i];
    memset(dp,0x3f,sizeof dp);
    dp[0] = 0;
    for (int i = 1;i <= n;i++)
        for (int j = p[i];j <= h + 5000;j++)
            dp[j] = min(dp[j],dp[j - p[i]] + c[i]);
    int ans = 1e9;
    for (int i = h;i <= h + 5000;i++) ans = min(ans,dp[i]);
    cout << ans << endl;
    return 0;
}