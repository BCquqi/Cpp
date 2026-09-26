#include<iostream>
using namespace std;

int mp[] = {1,2,4,7,8,11,13,14};

int main() {
    freopen("num.in","r",stdin);
    freopen("num.out","w",stdout);
    long long n;
    cin >> n;
    n--;
    cout << n / 8 * 15 + mp[n % 8] << endl;
    return 0;
}