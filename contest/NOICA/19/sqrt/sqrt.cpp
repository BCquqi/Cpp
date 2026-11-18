#include<iostream>
#include<algorithm>
#include<cmath>
#define int long long
using namespace std;

const int N = 2e6 + 5;
int n,m;
int pri[N],cnt1[N],cnt2[N],cur = 0;

inline int calc(int x,int y) {
    int ret = 0;
    while (x % y == 0) x /= y, ret++;
    return ret;
}

inline void init() {
    for (int i = 1;i <= n;i++) pri[i] = 1;
    for (int i = 2;i <= n;i++) {
        if (pri[i] > 1) continue;
        for (int j = 2;i * j <= n;j++)
            pri[i * j] *= calc(i * j,i);
    }
    for (int i = 1;i <= n;i++)
        if (pri[i] == 1)
            cnt1[++cur] += floor(sqrt(n / i)), 
            cnt2[cur] += floor(sqrt(m / i));
    return ;
}

signed main() {
    freopen("sqrt.in","r",stdin);
    freopen("sqrt.out","w",stdout);
    cin >> n >> m;
    if (n > m) swap(n,m);
    init();
    long long ans = 0;
    for (int i = 1;i <= cur;i++)
        ans += cnt1[i] * cnt2[i];
    cout << ans << endl;
    return 0;
}