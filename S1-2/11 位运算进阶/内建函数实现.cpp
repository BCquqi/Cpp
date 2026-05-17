#include<iostream>
#include<algorithm>
using namespace std;

int n = 123456789;

int main() {
    // 1. 求二进制中1的个数

    __builtin_popcount(n); // O(log log n)

    int cnt = 0;
    while (n)
        cnt += n & 1,n >>= 1; // O(log n)

    // 2. 求二进制中1的个数的奇偶性

    __builtin_parity(n); // O(log log n)

    int cnt = 0;
    while (n)
        cnt ^= n & 1,n >>= 1; // O(log n)
    bool parity = cnt & 1;

    // 3. 求前导0个数

    __builtin_clz(n); // O(log log n)

    (1 << j) > x

    // 4. 求末尾0的个数

    __builtin_ctz(n); // O(log log n)

    x & -x
    (x & (1 << j)) == 1;
}