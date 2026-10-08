#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <string>
#define i128 __int128
using namespace std;

i128 x, v, s;

inline i128 read() {
    string str;
    cin >> str;
    int p = 0, sign = 1;
    if (str[p] == '-') sign = -1, p++;
    i128 num = 0;
    for (; p < (int)str.size(); p++) num = num * 10 + str[p] - '0';
    return num * sign;
}

inline void write(i128 x) {
    if (x < 0) {putchar('-'); x = -x;}
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

i128 isqrt(i128 n) {
    if (n == 0) return 0;
    i128 x = n, y = (x + n / x) >> 1;
    while (y < x) {x = y, y = (x + n / x) >> 1;}
    return x;
}

bool check(i128 k) {
    if (k < 0) return false;
    i128 tmpmin = x * (x + 1) / 2 + k * v * (v + 1) / 2, tmpmax = (x + k * (v - 1)) * (x + k * (v - 1) + 1) / 2 + k * x + v * k * (k + 1) / 2 - k * (k - 1) / 2;
    return s >= tmpmin && s <= tmpmax && (s % v == tmpmin % v);
}

int main() {
    freopen("bike.in", "r", stdin);
    freopen("bike.out", "w", stdout);
    i128 t = read();
    while (t--) {
        x = read(), v = read(), s = read();
        if (s < x * (x + 1) / 2) {write(-1); cout << endl; continue;}
        if (v == 0) {
            if (s == x * (x + 1) / 2) write(0);
            else write(-1);
            cout << endl;
            continue;
        } else if (v == 1) {
            i128 diff = s - x * (x + 1) / 2, k = (diff + x) / (x + 1);
            if (k <= diff) write(k);
            else write(-1);
            cout << endl;
            continue;
        }
        i128 A = v * (v - 1), B = 2 * v * (x + 1), C = x * (x + 1) - 2 * s, delta = B * B - 4 * A * C;
        i128 root = isqrt(delta), num = -B + root, den = 2 * A, k0 = 0;
        if (num > 0) k0 = (num + den - 1) / den;
        i128 ans = -1, l = max((i128)0, k0 - 3);
        for (i128 k = l; k <= k0 + 3; k++)
            if (check(k)) {ans = k; break;}
        write(ans);
        cout << endl;
    }
    return 0;
}