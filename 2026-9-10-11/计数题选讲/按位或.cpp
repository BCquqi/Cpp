#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

const int N = 1 << 20;
double p[N],f[N];

signed main() {
    int n;
    cin >> n;
    int mx = 1 << n;
    for (int i = 0;i < mx;i++) cin >> p[i], f[i] = p[i];
    for (int j = 0;j < n;j++)
        for (int i = 0;i < mx;i++)
            if (i & (1 << j)) f[i] += f[i ^ (1 << j)];
            
    double ans = 0;
    for (int s = 1;s < mx;s++) {
        double tmp = 1.0 - f[(mx - 1) ^ s];
        if (tmp < 1e-10) {
            printf("INF\n");
            return 0;
        }
        int cnt = __builtin_popcount(s);
        if (cnt & 1) ans += 1.0 / tmp;
        else ans -= 1.0 / tmp;
    }
    printf("%.7lf\n", ans);
    return 0;
}