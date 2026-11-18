#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long L = 1, R = 2e9, k = 0;
    while (L <= R) {
        long long mid = L + (R - L) / 2;
        if (mid * (mid + 1) / 2 <= n + 1) {
            k = mid;
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    cout << n - k + 1 << endl;
    return 0;
}