#include<iostream>
#include<algorithm>
using namespace std;

const int N = 55,T = 1e5 + 5;
struct Food {long long a,b,c;} s[N]; // 每个好恰滴要排序，所以用结构体
long long dp[T];

bool cmp(Food x,Food y) {
    return x.c * y.b < x.b * y.c; // 排序后的顺序是最优的
}

int main() {
    int t,n;
    cin >> t >> n;
    for (int i = 1;i <= n;i++) cin >> s[i].a;
    for (int i = 1;i <= n;i++) cin >> s[i].b;
    for (int i = 1;i <= n;i++) cin >> s[i].c;
    sort(s + 1,s + n + 1,cmp);
    for (int i = 1;i <= n;i++)
        for (int j = t;j >= s[i].c;j--) // 用时
            dp[j] = max(dp[j],dp[j - s[i].c] + s[i].a - j * s[i].b);
    long long ans = 0;
    for (int i = 0;i <= t;i++) ans = max(ans,dp[i]);
    cout << ans << endl;
    return 0;
}