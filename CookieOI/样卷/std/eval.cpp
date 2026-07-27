#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int SIGNS[8][3] = {{1,1,1},{1,1,-1},{1,-1,1},{1,-1,-1},{-1,1,1},{-1,1,-1},{-1,-1,1},{-1,-1,-1}};

int main() {
    freopen("eval.in", "r", stdin);
    freopen("eval.out", "w", stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> x(n), y(n), z(n);
    for (int i = 0; i < n; ++i) scanf("%d%d%d", &x[i], &y[i], &z[i]);
    long long ans = 0;
    for (int t = 0; t < 8; ++t) {
        vector<long long> v;
        v.reserve(n);
        int sx = SIGNS[t][0], sy = SIGNS[t][1], sz = SIGNS[t][2];
        for (int i = 0; i < n; ++i) v.push_back(1LL * x[i] * sx + 1LL * y[i] * sy + 1LL * z[i] * sz);
        sort(v.begin(), v.end(), greater<long long>());
        long long sum = 0;
        for (int i = 0; i < k; ++i) sum += v[i];
        if (sum > ans) ans = sum;
    }
    printf("%lld\n", ans);
    return 0;
}