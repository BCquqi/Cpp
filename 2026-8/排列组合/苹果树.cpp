#include<iostream>
#define int long long
using namespace std;

const int N = 2005;
int c[N][N],fac[N],n,p;

/*
第一次有 1 种选择，第二次有 2 种选择，第三次有 3 种选择，所以 n 步的总情况数就是 n!
---
由于难以在题目要求 O(n^2) 时间复杂度内枚举点对求最短距离和
所以不妨等价转换为枚举边对求经过点对数量和
---
对于点 i 的父亲边进行思考
由于子树内点对路径不影响这条边答案，所以只需要记录这个子节点和子树外的点的影响即可
所以，其对距离和的贡献就是 size[i] * (n - size[i])
由于是 O(n^2) 的复杂度，可以一维枚举 i 一维枚举 size
---
然后对于一个子树，还要分析里面的可能排列情况和编号情况
然后就是列式了
*/

void init() {
    // 组合数
    for (int i = 0;i <= n;i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1;j <= i;j++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % p;
    }
    // 阶乘
    fac[0] = 1;
    for (int i = 1;i <= n;i++)
        fac[i] = fac[i - 1] * i % p;
    return ;
}

signed main() {
    cin >> n >> p;
    init();
    long long ans = 0;
    for (int i = 2;i <= n;i++)
        for (int siz = 1;siz <= n - i + 1;siz++)
            ans += fac[siz] * c[n - i][siz - 1] % p * siz % p * (n - siz) % p * fac[n - siz - 1] % p * i % p * (i - 1) % p, 
            ans %= p;
    cout << ans << endl;
    return 0;
}