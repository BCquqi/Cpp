#include<cstdio>
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

signed main(){
    int a,b;
    cin >> a >> b;
    int x = 0,y = 0;
    exgcd(a,b,x,y);
    x = (x % b + b) % b;
    cout << x << endl;
    return 0;
}