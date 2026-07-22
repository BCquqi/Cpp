#include<iostream>
using namespace std;

int main() {
    int a,b,c,d,e,ans = 0;
    cin >> a >> b >> c >> d >> e;
    e += a / 3,b += a / 3,ans += a % 3,a /= 3;
    a += b / 3,c += b / 3,ans += b % 3,b /= 3;
    b += c / 3,d += c / 3,ans += c % 3,c /= 3;
    c += d / 3,e += d / 3,ans += d % 3,d /= 3;
    d += e / 3,a += e / 3,ans += e % 3,e /= 3;
    cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << endl << ans << endl;
    return 0;
}