#include<iostream>
using namespace std;

const int N = 1e7 + 5;
long long x[N];

int main() {
    int n,a,b,c,d;
    long long cnt1 = 0,cnt2 = 0;
    cin >> n >> a >> b >> c >> d >> x[0];
    for (int i = 1;i <= n;i++)
        x[i] = 1ll * (a * x[i - 1] % d * x[i - 1] % d + b * x[i - 1] % d + c) % d;
    for (int i = 1;i <= n;i++)
        if (__builtin_parity(x[i])) cnt1++;
        else cnt2++;
    cout << 1ll * cnt1 * cnt2 << endl;
    return 0;
}