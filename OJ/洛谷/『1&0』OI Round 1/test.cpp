#include<iostream>
#include<vector>
using namespace std;

int main() {
    freopen("test.txt","w",stdout);
    int n;
    cin >> n;
    n = (1 << n) - 1;
    cout << n << endl;
    vector<int> a(n+1), cp(n+1);
    for (int i = 1; i <= n; i++) a[i] = i;
    for (int round = 1; round <= 1000; round++) {
        for (int i = 1; i <= n; i++) {
            int next = i == n ? 1 : i + 1;
            cp[i] = a[i] ^ a[next];
        }
        for (int i = 1; i <= n; i++) {
            a[i] = cp[i];
            cout << a[i];
            if (i < n) cout << ' ';
        }
        cout << endl;
    }
    return 0;
}