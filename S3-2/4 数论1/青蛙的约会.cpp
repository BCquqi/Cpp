#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

long long exgcd(long long a,long long b,long long &x,long long &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    long long d = exgcd(b,a % b,x,y),t = x;
    x = y, y = (t - a / b * y);
    return d;
}

signed main() {
    int x,y,m,n,l;
    cin >> x >> y >> m >> n >> l;
    int a = m - n,b = l,c = y - x;
    if (a < 0) a = -a, c = -c;
    if (c % __gcd(a,b) != 0) {
        cout << "Impossible" << endl;
        return 0;
    }
    int xx,yy;
    exgcd(a,b,xx,yy);
    int ans1 = b / __gcd(a,b),ans2 = c / __gcd(a,b);
    cout << (xx % ans1 * ans2 % ans1 + ans1) % ans1 << endl;
    return 0;
}