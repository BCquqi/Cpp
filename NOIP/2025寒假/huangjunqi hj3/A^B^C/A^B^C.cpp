#include<iostream>
using namespace std;

long long qpow(long long a,long long b,long long p) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int main() {
    long long a,b,c;
    cin >> a >> b >> c;
    a %= 10;
    if (a == 0 || a == 1 || a == 5 || a == 6) cout << a << endl;
    else if (a == 2 || a == 3 || a == 7 || a == 8) cout << qpow(a, qpow(b, c, 4) + 4, 10) << endl;
    else cout << qpow(a, qpow(b, c, 2) + 2, 10) << endl;
    return 0;
}