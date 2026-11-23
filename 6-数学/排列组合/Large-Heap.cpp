#include<iostream>
#define int long long
using namespace std;

const int N = 5005,mod = 998244353;
int inv[N][N],dp[N][N],p[N]; // 乘法逆元
int n,a,b;

/*
p[i] < p[2i], p[i] < p[2i + 1]
---
可以将数组 p 抽象成二叉树形式，则这个二叉树是小根堆
而所求的 p[2 ^ a] < p[2 ^ (b + 1) - 1] 则恰好是小根堆两侧斜坡上的数字
因此，对答案做出贡献的只有小根堆的两侧，其余不影响答案
---
考虑使用 dp。
状态定义：dp[i][j] 表示处理到剩下深度为 i 和深度为 j 的子树的合并拓扑总方案数
通过 dp 推概率即可
本代码的 dp 直接用于记录概率
---
一篇值得参考复习的题解：
https://www.luogu.com.cn/article/i2yjbslg
*/

long long qpow(long long a,long long b,long long p) {
    long long ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

void init() {
    for (int i = 1;i <= n;i++) p[i] = qpow(2,i,mod); // 提前处理，加快速度，减少不必要的运算量
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            inv[i][j] = (p[i] - 1) * qpow(p[i] + p[j] - 2,mod - 2,mod) % mod;
    for (int i = n - b;i <= n;i++) dp[n - a - 1][i] = 1;
}

signed main() {
    cin >> n >> a >> b;
    init();
    for (int i = n - a;i <= n;i++)
        for (int j = n - b;j <= n;j++)
            dp[i][j] = (dp[i - 1][j] * inv[i][j] % mod + dp[i][j - 1] * inv[j][i] % mod) % mod;
    cout << dp[n - 1][n - 1] << endl;
    return 0;
}