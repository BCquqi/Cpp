#include<iostream>
#define int long long
using namespace std;

inline int read()
{
    int x = 0,f = 1;
    char ch = getchar_unlocked();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar_unlocked();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - 48; ch = getchar_unlocked();}
    return x * f;
}

inline void write(int x)
{
    if (x < 0) {putchar('-'); x = -x;}
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

signed main() {
    int n = read(),sum = 0;
    for (int i = 1;i <= n;i++) {
        int x = read();
        sum += x;
    }
    write(sum);
    putchar('\n');
    return 0;
}