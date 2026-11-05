#include<iostream>
using namespace std;

void solve() {
    long long h,d,k;
    cin >> h >> d >> k;
    int cnt = 0;
    while (h > 0) {
        cnt++;
        if (h >= (long long)1e16 || cnt > 100) {
            cout << -1 << endl;
            return ;
        }
        h *= 2, h -= d, d += k;
    }
    if (h > 0) cout << -1 << endl;
    else cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("tang.in","r",stdin);
    freopen("tang.out","w",stdout);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
