#include<iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,ans = 0;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int a;
        cin >> a;
        ans ^= a;
    }
    cout << ans << endl;
    return 0;
}