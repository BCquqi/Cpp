#include<iostream>
#include<algorithm>
#define int __int128
using namespace std;

const int N = 1e6 + 5;
long long a[N],b[N],cur = 0;

bool check(int x,int y,int n) {
    int sum = 0;
    for (int i = 1;i <= n;i++)
        sum += x / a[i];
    return sum <= y;
}

long long calc(int x) {
    int m = cur,ret = 0;
    for (int i = 1; i < (1 << m); i++) {
        long long lcm = 1;
        bool flag = true;
        for (int j = 0;j < m;j++)
            if ((i >> j) & 1) {
                int tmp = (int)lcm / __gcd(lcm,b[j + 1]) * b[j + 1];
                if (tmp > x) {
                    flag = false;
                    break;
                }
                lcm = tmp;
            }
        if (flag)
            if (__builtin_popcount(i) & 1) ret += x / lcm;
            else ret -= x / lcm;
    }
    return ret;
}

long long solve(int x,int n) {
    int l = 0,r = min(x * b[1],(int)1e18),ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid,x,n)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    return calc(ans);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    long long n,l,r;
    cin >> n >> l >> r;
    for (int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + n + 1);
    for (int i = 1;i <= n;i++) {
        bool flag = true;
        for (int j = 1;j <= cur;j++)
            if (a[i] % b[j] == 0) {
                flag = false;
                break;
            }
        if (flag) b[++cur] = a[i];
    }
    cout << solve(r,n) - solve(l - 1,n) << endl;
    return 0;
}