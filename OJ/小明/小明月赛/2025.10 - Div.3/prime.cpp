#include<iostream>
using namespace std;

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2;i * i <= x;i++)
        if (x % i == 0) return false;
    return true;
}

int main() {
    freopen("prime.in", "r", stdin);
    freopen("prime.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1;i <= n / 2;i++)
        if (is_prime(i) && is_prime(n - i)) {
            cout << i << " " << n - i << endl;
            return 0;
        }
    return 0;
}