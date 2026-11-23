#include<iostream>
#define int long long
using namespace std;

const int N = 1e5 + 5;
int dp[N],c[5],d[5],n,s;
// dp[j] 表示刚好凑出 j 的总方法数

void init() {
    dp[0] = 1;
    for (int i = 1;i <= 4;i++)
        for (int j = c[i];j <= 1e5;j++)
            dp[j] += dp[j - c[i]];
    return ;
}

signed main() {
    cin >> c[1] >> c[2] >> c[3] >> c[4] >> n;
    init();
    while (n--) {
        cin >> d[1] >> d[2] >> d[3] >> d[4] >> s;
        long long ans = dp[s];
        for (int i = 1;i < 16;i++) { // 二进制枚举容斥
            int cnt = 0,tmp = 0;
            for (int j = 1;j <= 4;j++)
                if ((i >> (j - 1)) & 1)
                    cnt++, tmp += c[j] * (d[j] + 1);
            if (s >= tmp) ans += (cnt % 2 ? -1 : 1) * dp[s - tmp];
        }
        cout << ans << endl;
    }
    return 0;
}