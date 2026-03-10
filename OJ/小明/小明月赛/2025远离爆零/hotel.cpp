#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    freopen("hotel.in", "r", stdin);
    freopen("hotel.out", "w", stdout);
    int n,k,x,y;
    cin >> n >> k >> x >> y;
    if (n <= k) cout << n * x << endl;
    else cout << k * x + (n - k) * y << endl;
    return 0;
}