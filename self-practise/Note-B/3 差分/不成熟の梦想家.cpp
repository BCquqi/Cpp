#include<iostream>
#define int long long
using namespace std;

const int N = 2e5 + 5;
int a[N],d[N],n,q,s,t,ans = 0;

inline int cal(int x) {return x > 0 ? -s * x : -t * x;}

signed main() {
    cin >> n >> q >> s >> t;
    for (int i = 0;i <= n;i++) {
        cin >> a[i];
        if (i) d[i] = a[i] - a[i - 1];
        ans += cal(d[i]);
    }
    while (q--) {
        int x,y,z;
        cin >> x >> y >> z;
        ans -= cal(d[x]);
        d[x] += z;
        ans += cal(d[x]);
        if (y != n) {
            ans -= cal(d[y + 1]);
            d[y + 1] -= z;
            ans += cal(d[y + 1]);
        }
        cout << ans << endl;
    }
    return 0;
}