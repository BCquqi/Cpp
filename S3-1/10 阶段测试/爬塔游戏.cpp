#include<iostream>
#include<algorithm>
using namespace std;

const int N = 30,M = 1e6 + 5;
int a[N],c[M],n,m,h[(1 << 24) + 5],dp[(1 << 24) + 5];

// h[i] 表示状态 i 时达到的高度

int main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= m;i++) cin >> c[i];
    for (int i = 0;i < (1 << n);i++) {
        for (int j = 0;j < n;j++)
            if ((i >> j) & 1) h[i] += a[j];
    }
    for (int i = 0;i < (1 << n);i++) // 现在的状态
        for (int j = 0;j < n;j++) // 上次跳是哪一位
            if ((i >> j) & 1) dp[i] = max(dp[i],dp[i ^ (i & -i)] + c[h[i]]); // 取出第 j 位的状态加上现在的高度
    cout << dp[(1 << n) - 1] << endl;
    return 0;
}