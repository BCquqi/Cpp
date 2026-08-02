#include<iostream>
using namespace std;

string s;
long long n,cpy;

char merge(long long n,long long len) {
    if (n <= cpy) return s[n]; // 映射成功
    long long x = n - len - 1,y = len; // 目标在后半段就映射到前半段
    // x 是映射后的位置，y 是下一步映射的半长
    if (x == 0) x = y;
    while (y >= x) y /= 2;
    return merge(x,y);
}

int main() {
    cin >> s >> n;
    long long len = s.size();
    cpy = len;
    s = '?' + s;
    while (len < n) len *= 2; // 倍增字符串
    len /= 2; // len 是半长
    cout << merge(n,len) << endl;
    return 0;
}