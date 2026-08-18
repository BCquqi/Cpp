#include<iostream>
#define int long long
using namespace std;

const int N = 1e5 + 5;
int a[N];

signed main() {
    int n,x,ans = 0;
    cin >> n >> x;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        if (a[i] + a[i - 1] > x) ans += (a[i] + a[i - 1] - x),a[i] -= (a[i] + a[i - 1] - x);
    }
    cout << ans << endl;
    return 0;
}