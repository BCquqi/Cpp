#include <cstdio>
#include <algorithm>
using namespace std;

int get(int x, int p) {
    int c = 0;
    while (x) {
        x /= p;
        c += x;
    }
    return c;
}

int main() {
    freopen("percom.in", "r", stdin);
    freopen("percom.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    int n2 = get(n, 2), n5 = get(n, 5);
    int m2 = get(m, 2), m5 = get(m, 5);
    int nm2 = get(n - m, 2), nm5 = get(n - m, 5);
    int ans1 = min(n2 - nm2, n5 - nm5);
    int ans2 = min(n2 - m2 - nm2, n5 - m5 - nm5);
    printf("%d %d\n", ans1, ans2);
    return 0;
}