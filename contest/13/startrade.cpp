#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

signed main() {
    freopen("startrade.in","r",stdin);
    freopen("startrade.out","w",stdout);
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    b += a / 3, c += b / 3;
    cout << min(c,(c + 3 * d) / 4) << endl;
    return 0;
}