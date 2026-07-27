#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

// 01 背包变形

const int N = 505;
struct Node {int a,b;} s[N];
int a[N],b[N],dp[2][N * N];

// dp[i][j] 表示前 i 个人，1 号窗口打饭总时间为 j 时，前 i 个人吃完饭的最短时间

int main() {
    freopen("meal.in","r",stdin);
    freopen("meal.out","w",stdout);
    int n,sum = 0;
    cin >> n;
    for (int i = 1;i <= n;i++)
        cin >> s[i].a >> s[i].b;
    memset(dp,0x3f,sizeof dp);
    dp[0][0] = 0;
    sort(s + 1,s + n + 1,[](Node x,Node y) {return x.b > y.b;}); // 贪心，吃饭时间长优先考虑
    int tmp = 0; // 动态更新前 i - 1 个人的总拿饭时长
    for (int i = 1;i <= n;i++) {
        sum += s[i].a;
        for (int j = 0; j <= sum; j++) dp[i & 1][j] = 0x3f3f3f3f;
        for (int j = 0;j <= sum;j++) { // 第 i 个人拿完饭后，1 的总时间
            if (tmp - j >= 0) dp[i & 1][j] = min(dp[i & 1][j],max(dp[i - 1 & 1][j],tmp - j + s[i].a + s[i].b)); // tmp - j 就是二号窗的总时间
            if (j >= s[i].a) dp[i & 1][j] = min(dp[i & 1][j],max(dp[i - 1 & 1][j - s[i].a],j + s[i].b)); // 之前的最晚和第 i 个人的最晚
        }
        tmp += s[i].a;
    }
    int ans = 1e9;
    for (int i = 0;i <= sum;i++) ans = min(ans,dp[n & 1][i]);
    cout << ans << endl;
    return 0;
}