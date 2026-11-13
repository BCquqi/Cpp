#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 2005;
struct Range {int l,r;} a[N],b[N];
int cur = 0;
int dp[N][N]; // dp[i][j] The answer when visit i and choose j stamps, especially choose the ist. 

void solve(int cid) {
    cur = 0, b[0] = {0,0};
    int n,m,K;
    cin >> n >> m >> K;
    for (int i = 1;i <= m;i++)
        cin >> a[i].l >> a[i].r;
    sort(a + 1,a + m + 1,[](Range x,Range y) {return (x.l != y.l) ? x.l < y.l : x.r > y.r;});
    int maxr = 0;
    for (int i = 1;i <= m;i++)
        if (a[i].r > maxr) b[++cur] = a[i], maxr = a[i].r;
    memset(dp,-1,sizeof dp);
    dp[0][0] = 0;
    for (int i = 1;i <= cur;i++)
        for (int j = 1;j <= i && j <= K;j++)
            for (int k = 0;k < i;k++) { // the last one chosen
                if (dp[k][j - 1] == -1) continue;
                if (b[i].l > b[k].r) // no intersection
                    dp[i][j] = max(dp[i][j],dp[k][j - 1] + (b[i].r - b[i].l + 1));
                else 
                    dp[i][j] = max(dp[i][j],dp[k][j - 1] + (b[i].r - b[k].r));
            }
    int ans = 0;
    for (int i = 1;i <= cur;i++)
        for (int j = 0;j <= K;j++)
            ans = max(ans,dp[i][j]);
    cout << "Case #" << cid << ": " << ans << endl;
    return ;
}

int main() {
    int T;
    cin >> T;
    for (int cid = 1;cid <= T;cid++) solve(cid);
    return 0;
} 