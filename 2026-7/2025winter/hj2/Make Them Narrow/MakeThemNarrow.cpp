#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2e5 + 5;
int a[N];

int main() {
    int n,k,ans = 1e9;
    cin >> n >> k;
    for (int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + n + 1);
    for (int i = 0;i <= k;i++) ans = min(ans,abs(a[n - (k - i)] - a[i + 1]));
    cout << ans << endl;
    return 0;
}