#include<iostream>
using namespace std;

const int N = 3e6 + 5;
int inv[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,p;
    cin >> n >> p;
    inv[1] = 1;
    cout << 1 << '\n';
    for (int i = 2;i <= n;i++) {
        inv[i] = p - (1ll * p / i * inv[p % i]) % p;
        cout << inv[i] << '\n';
    }
    return 0;
}