#include<iostream>
using namespace std;

void solve() {
    int n;
    long long a[105];
    cin >> n;
    a[1] = 1;
    for (int i = 2;i <= n;i++) {
        a[i] = a[i - 1] * 3;
        if (a[i] > 1e9) {
            cout << "NO" << endl;
            return ;
        }
    }
    cout << "YES" << endl;
    for (int i = 1;i <= n;i++) cout << a[i] << ' ';
    cout << endl;
    return ;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}