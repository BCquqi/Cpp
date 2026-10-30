#include<iostream>
using namespace std;

signed main() {
    freopen("gcd.in","r",stdin);
    freopen("gcd.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    for (int d = 1; d <= n / 2; d++)
        for (int a = d; a <= n - d; a += d) {
            int b = a + d;
            if (d == (a ^ b)) ans++;
        }
    cout << ans << endl;
    return 0;
}