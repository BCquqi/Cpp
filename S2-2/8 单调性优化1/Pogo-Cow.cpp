#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1e3 + 5;
struct Node {int x,p;} a[N];
int dp[N][N];

// dp[i][j]: 当前位置为 i, 且从 j 跳跃到 i 的最大得分

int main() {
    int n,ans = 0;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i].x >> a[i].p;
        ans = max(ans,a[i].p);
    }
    // 从左到右
    sort(a + 1,a + n + 1,[](Node x,Node y) {return x.x < y.x;});
    for (int j = 0;j < n;j++) {
        int k = j - 1,value = a[j].p;
        for (int i = j + 1;i <= n;i++) {
            int dis = a[i].x - a[j].x;
            while (k >= 0 && (a[j].x - a[k].x) <= dis)
                value = max(value,dp[j][k]),k--;
            dp[i][j] = value + a[i].p;
            ans = max(ans,dp[i][j]);
        }
    }
    // 从右到左
    memset(dp,0,sizeof dp);
    for (int i = 1;i <= n;i++) a[i].x = 1e6 - a[i].x;
    sort(a + 1,a + n + 1,[](Node x,Node y) {return x.x < y.x;});
    for (int j = 0;j < n;j++) {
        int k = j - 1,value = a[j].p;
        for (int i = j + 1;i <= n;i++) {
            int dis = a[i].x - a[j].x;
            while (k >= 0 && (a[j].x - a[k].x) <= dis)
                value = max(value,dp[j][k]),k--;
            dp[i][j] = value + a[i].p;
            ans = max(ans,dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}