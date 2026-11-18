#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2e7 + 5;
int lg[N];
long long s[N];

namespace fastIO {
    inline int read() {
        int x = 0,f = 1;
        char ch = getchar();
        while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
        while (ch >= '0' && ch <= '9') {x = x * 10 + ch - 48; ch = getchar();}
        return x * f;
    }
    inline void write(long long x) {
        if (x < 0) {putchar('-'); x = -x;}
        if (x > 9) write(x / 10);
        putchar(x % 10 + '0');
    }
};

using namespace fastIO;

void init(int lim) {
    lg[1] = 1;
    for (int i = 2;i <= lim;i++) lg[i] = lg[i / 2] + 1;
    for (int i = 1;i <= lim;i++)
        s[i] = s[i - 1] + (1 << (lg[i] - (__builtin_popcount(i))));
    return ;
}

int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = read();
    int lim = 2e7;
    init(lim);
    for (int i = 1;i <= T;i++) {
        int l = read(),r = read();
        write(s[r] - s[l - 1]);
        putchar('\n');
    }
    return 0;
}