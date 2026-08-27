#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
    int n,ans = 0;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int a;
        cin >> a;
        ans = __gcd(ans,abs(a));
    }
    cout << ans << endl;
    return 0;
}