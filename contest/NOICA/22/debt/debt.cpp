#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N = 1e5 + 5;
int s[N],n,m;

signed main() {
    freopen("debt.in","r",stdin);
    freopen("debt.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int x,y,z;
        cin >> x >> y >> z;
        s[x] -= z, s[y] += z;
    }
    long long ans = 0;
    for (int i = 1;i <= n;i++)
        if (s[i] > 0) ans += s[i];
    cout << ans / 10 << '.' << ans % 10 << endl;
    return 0;
}