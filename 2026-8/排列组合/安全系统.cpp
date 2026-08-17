#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const __int128 N = 55;
__int128 f[N],g[N];

__int128 qpow(__int128 a,__int128 b) {
    __int128 ans = 1;
    while (b) {
        if (b & 1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}

__int128 query(__int128 n,__int128 m) {
    __int128 ans = 1;
    for (int i = 1;i <= n;i++)
        ans *= m - i + 1,ans /= i;
    return ans;
}

__int128 input() {
    __int128 x = 0;
    char ch = getchar();
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x;
}

void output(__int128 x) {
    if (x > 9) output(x / 10);
    putchar(x % 10 + '0');
}

signed main() {
    __int128 n,a,b;
    n = input(); a = input(); b = input();
    output(query(n,a + n) * query(n,b + n));
    return 0;
}