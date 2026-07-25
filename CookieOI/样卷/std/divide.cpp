#include <cstdio>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    freopen("divide.in", "r", stdin);
    freopen("divide.out", "w", stdout);
    int n, s;
    scanf("%d%d", &n, &s);
    vector<long long> sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        sum[i] = sum[i - 1] + x;
    }
    vector<long long> f(n + 1, 0);
    f[0] = 1;
    int l = 0;
    long long w = 0;
    for (int i = 1; i <= n; ++i) {
        w += f[i - 1];
        if (w >= MOD) w -= MOD;
        while (l <= i - 1 && sum[l] < sum[i] - s) {
            w -= f[l];
            if (w < 0) w += MOD;
            ++l;
        }
        f[i] = w;
    }
    printf("%lld\n", f[n]);
    return 0;
}