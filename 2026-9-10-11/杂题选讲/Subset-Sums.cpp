#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e6 + 5;
int a[N];

void solve() {
    int n;
    cin >> n;
    long long s = 0,ans = 0;
    for (int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + n + 1);
    for (int i = 1;i <= n;i++) {
        if (a[i] > s) ans = max(ans,a[i] - s);
        s += a[i];
    }
    cout << ans << '\n';
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}