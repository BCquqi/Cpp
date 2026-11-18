#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2e5 + 5;
int a[N];

int main() {
    int n,k,x;
    long long ans = 0;
    cin >> n >> k >> x;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++) {
        if (k == 0) break;
        int use = min(k,a[i] / x);
        k -= use,a[i] -= use * x;
    }
    sort(a + 1,a + n + 1,greater<int>());
    if (k > 0) for (int i = k + 1;i <= n;i++) ans += a[i];
    else for (int i = 1;i <= n;i++) ans += a[i];
    cout << ans << endl;
    return 0;
}