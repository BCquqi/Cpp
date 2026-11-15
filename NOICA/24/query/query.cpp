#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

const int N = 5e6 + 5;
int a[N],n,m,v;
set<int> s;

char buf[1 << 20], *p1 = buf, *p2 = buf;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) ? EOF : *p1++)

inline int read() {
    int x = 0; char c = getchar();
    for (; c < '0' || c > '9'; c = getchar());
    for (; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = getchar());
    return x;
}

int calc() {
    if (s.size() >= 30) return 0;
    long long res = 1;
    for (auto id : s) {
        res *= a[id];
        if (res >= v) return 0;
    }
    return res;
}

int main() {
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    n = read(),m = read(),v = read();
    for (int i = 1;i <= n;i++) {
        a[i] = read();
        if (a[i] > 1) s.insert(i);
    }
    int ans = calc();
    while (m--) {
        int x = read(),y = read();
        if (a[x] > 1) s.erase(x);
        a[x] = y;
        if (a[x] > 1) s.insert(x);
        ans ^= calc();
    }
    cout << ans << endl;
    return 0;
}