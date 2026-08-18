#include<iostream>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    if (n > m) swap(n,m);
    long long squ = 0,rec = 1ll * n * (n + 1) / 2 * m * (m + 1) / 2;
    for (int i = 1;i <= n;i++) squ += (n - i + 1) * (m - i + 1);
    cout << squ << ' ' << rec - squ << endl;
    return 0;
}