#include<iostream>
#define int long long
using namespace std;

const int N = 1e7 + 5;
int f[N]; // 大致在 O(log n) 左右

signed main() {
    int n;
    cin >> n;
    f[1] = 1, f[2] = 2;
    for (int i = 3;i <= 10000000;i++) f[i] = f[i - 1] + f[i - 2];
    while (n > 0) {
        if (n == 1 || n == 2) {
            cout << n << endl;
            break;
        }
        else {
            int cur = 1;
            while (f[cur] < n) ++cur;
            if (f[cur] == n) {
                cout << n << endl;
                break;
            }
            else n -= f[cur - 1];
        }
    }
    return 0;
}