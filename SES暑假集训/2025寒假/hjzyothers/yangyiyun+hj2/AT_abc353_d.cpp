#include <iostream>
#include <vector>
using namespace std;
const int MOD = 998244353;
long long pow10(long long x) {
    long long res = 1;
    do {
        res = (res * 10) % MOD;
        x /= 10;
    } while (x > 0);
    return res;
}
int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    long long sum_total = 0;
    long long pre_sum = 0;
    for (int j = 0; j < N; ++j) {
        long long p10 = pow10(A[j]);
        sum_total = (sum_total + pre_sum * p10) % MOD;
        sum_total = (sum_total + A[j] * j) % MOD;
        pre_sum = (pre_sum + A[j]) % MOD;
    }
    cout << sum_total % MOD << endl;
    return 0;
}
