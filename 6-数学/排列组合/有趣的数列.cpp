#include<iostream>
#define int long long
using namespace std;

const int N = 2e6 + 5;
int n,p,prime[N],cur = 0;
bool flag[N];

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
    for (int i = 2;i <= 2 * n;i++) {
        if (!flag[i]) prime[++cur] = i;
        for (int j = 1;j <= cur && prime[j] * i <= 2 * n;j++) {
            flag[prime[j] * i] = true; // 所有因子 prime[j] 的所有倍数都标记
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

signed main() {
    cin >> n >> p;
    init();
    // 不保证 p 是质数，无法乘法逆元拆分
    long long ans = 1;
    // 勒让德公式
    for (int i = 1;i <= cur;i++) {
        int x = 0;
        int tmp = 2 * n;
        while (tmp)
            tmp /= prime[i], x += tmp;
        tmp = n;
        while (tmp)
            tmp /= prime[i], x -= tmp;
        tmp = n + 1;
        while (tmp)
            tmp /= prime[i], x -= tmp;
        ans *= qpow(prime[i],x,p), ans %= p;
    }
    cout << ans << endl;
    return 0;
}