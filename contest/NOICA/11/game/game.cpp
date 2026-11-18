#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 2e6 + 5;
int a[2][N],dp1[N][3],dp2[N][3];
int tmp1[3],tmp2[3];

void solve() {
    int n,m;
    cin >> n >> m;
    char c;
    for (int i = 1;i <= n;i++) cin >> c, a[0][i] = c - '0';
    for (int i = 1;i <= n;i++) cin >> c, a[1][i] = c - '0';
    memset(dp1,0,sizeof dp1);
    memset(dp2,0,sizeof dp2);
    int ans1 = 0,ans2 = 0;
    for (int i = 1;i <= n;i++) {
        if (a[0][i] + a[1][i] == 2)
            tmp1[0] = 1, tmp1[1] = 1, tmp1[2] = 2, 
            tmp2[0] = 1, tmp2[1] = 1, tmp2[2] = 2;
        else if (a[0][i] + a[1][i])
            tmp1[0] = -1, tmp1[1] = -1, tmp1[2] = 0, 
            tmp2[0] = (a[0][i] == 1) ? 1 : -1, 
            tmp2[1] = (a[1][i] == 1) ? 1 : -1, 
            tmp2[2] = 0;
        else 
            tmp1[0] = -1, tmp1[1] = -1, tmp1[2] = -2, 
            tmp2[0] = -1, tmp2[1] = -1, tmp2[2] = -2;
        dp1[i][0] = max({dp1[i - 1][0],dp1[i - 1][2],0}) + tmp1[0];
        dp1[i][1] = max({dp1[i - 1][1],dp1[i - 1][2],0}) + tmp1[1];
        dp1[i][2] = max({dp1[i - 1][0],dp1[i - 1][1],dp1[i - 1][2],0}) + tmp1[2];
        ans1 = max({ans1,dp1[i][0],dp1[i][1],dp1[i][2]});
        dp2[i][0] = max({dp2[i - 1][0],dp2[i - 1][2],0}) + tmp2[0];
        dp2[i][1] = max({dp2[i - 1][1],dp2[i - 1][2],0}) + tmp2[1];
        dp2[i][2] = max({dp2[i - 1][0],dp2[i - 1][1],dp2[i - 1][2],0}) + tmp2[2];
        ans2 = max({ans2,dp2[i][0],dp2[i][1],dp2[i][2]});
    }
    int ans = max({0,ans1,ans2 - 2 * m});
    cout << ans << endl;
}

int main() {
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int sub,T;
    cin >> sub >> T;
    while (T--) solve();
    return 0;
}