#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5,mod = 1e9 + 7;
int a[N];

int main() {
    int n;
    long long ans = 1;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + n + 1);
    for (int i = 1;i <= n;i++) ans *= a[i] - a[i - 1] + 1,ans %= mod;
    cout << ans << endl;
    return 0;
}

// https://atcoder.jp/contests/arc117/submissions/74033194