#include<iostream>
#define int long long
using namespace std;

signed main() {
    long long q;
    cin >> q;
    while (q--) {
        long long l,r;
        cin >> l >> r;
        if ((l + r) % 2 == 0)
            cout << (l + r) / 2 % 9 * (r - l + 1) % 9 << endl;
        else cout << (r - l + 1) / 2 % 9 * (l + r) % 9 << endl;
    }
    return 0;
}