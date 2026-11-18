#include<iostream>
using namespace std;

const int N = 1e5 + 5;
int a[2 * N],n,q;

void solve() {
    long long ans = 0,pre = 0;
    for (int i = 1;i <= n;i++) {
        int d = a[2 * i] - a[2 * i - 1] - pre;
        if (d > 0) {
            int cur = (d + 1) / 2;
            ans += cur, pre = cur;
        } else pre = 0;
    }
    cout << ans << '\n';
    return ;
}

int main() {
    freopen("overcoat.in","r",stdin);
    freopen("overcoat.out","w",stdout);
    cin >> n >> q;
    for (int i = 1; i <= 2 * n + 1; i++)
        cin >> a[i];
    solve();
    while (q--) {
        int x,v;
        cin >> x >> v;
        a[x] = v;
        solve();
    }
    return 0;
}