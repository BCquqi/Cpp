#include<iostream>
#include<algorithm>
using namespace std;

const int N = 510,KK = 110;
struct Node {int x,y;} a[N];
int dp[N][KK];

int main() {
    int n,K;
    cin >> n >> K;
    for (int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
    sort(a + 1,a + n + 1,[](Node p,Node q) {return (p.x != q.x ? p.x < q.x : p.y < q.y);});
    int ans = 0;
    for (int i = 1;i <= n;i++) {
        for (int k = 0;k <= K;k++) dp[i][k] = k + 1;
        for (int j = 1;j < i;j++) {
            if (a[j].x > a[i].x || a[j].y > a[i].y) continue;
            int d = a[i].x - a[j].x + a[i].y - a[j].y - 1;
            for (int k = d;k <= K;k++)
                dp[i][k] = max(dp[i][k],dp[j][k - d] + d + 1);
        }
        for (int k = 0;k <= K;k++) ans = max(ans,dp[i][k]);
    }
    cout << ans << endl;
    return 0;
}