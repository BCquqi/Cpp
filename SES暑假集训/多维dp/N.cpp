#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1005;
struct Boat {long long x,l,id;} s[N];
long long dp[N][N]; // 前 i 个海盗让 j 个海盗开心的船右端点坐标的最小值

void solve() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> s[i].x >> s[i].l;
        s[i].id = i;
    }
    sort(s + 1,s + n + 1,[](Boat x,Boat y) {return (x.x != y.x ? x.x < y.x : x.l > y.l);});
    memset(dp,0x3f,sizeof dp);
    if (s[1].id == 1) dp[1][1] = s[1].x + (s[1].l + 1) / 2;
    else dp[1][0] = -1e18,dp[1][1] = s[1].x;
    for (int i = 2;i <= n;i++) {
        if (s[i].id == 1) {
            for (int j = 1;j <= i;j++)
                if (dp[i - 1][j - 1] + (s[i].l + 1) / 2 <= s[i].x)
                    dp[i][j] = s[i].x + (s[i].l + 1) / 2;
        }
        else {
            for (int j = 0;j <= i;j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= 1 && dp[i - 1][j - 1] <= s[i].x) {
                    if (dp[i - 1][j - 1] + s[i].l <= s[i].x) dp[i][j] = min(dp[i][j],s[i].x);
                    else dp[i][j] = min(dp[i][j],dp[i - 1][j - 1] + s[i].l);
                }
            }
        }
    }
    for (int j = n;j >= 1;j--)
        if (dp[n][j] != 0x3f3f3f3f3f3f3f3f) {
            cout << j << endl;
            return ;
        }
    return ;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}