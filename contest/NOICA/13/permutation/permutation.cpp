#include<iostream>
using namespace std;

const int N = 2e5 + 5;
int a[N];

int main() {
    freopen("permutation.in","r",stdin);
    freopen("permutation.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n,s = 0;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        if (a[i] == n) s = i;
    }
    int cur = n,ans = 1;
    for (int i = s;i >= 1;i--)
        if (a[i] == cur - 1) cur--, ans++;
    cout << n - ans << endl;
    return 0;
}