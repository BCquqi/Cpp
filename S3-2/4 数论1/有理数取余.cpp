#include<iostream>
#define int long long
using namespace std;

const int p = 19260817;

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
    string s1,s2;
    cin >> s1 >> s2;
    int a = 0,b = 0;
    for (int i = 0;i < s1.size();i++) a = (a * 10 + s1[i] - '0') % p;
    for (int i = 0;i < s2.size();i++) b = (b * 10 + s2[i] - '0') % p;
    if (b == 0) {
        cout << "Angry!" << endl;
        return 0;
    }
    int x,y;
    exgcd(b,p,x,y);
    x = (x % p + p) % p;
    cout << x * a % p << endl;
    return 0;
}