#include<iostream>
using namespace std;

int main() {
    long long h,d,k;
    cin >> h >> d >> k;
    int lim;
    cin >> lim;
    int cnt = 0;
    while (h >= 0 && ++cnt <= lim) {
        h <<= 1, h -= d, d += k;
        cout << h << ' ' << d << ' ' << k << endl;
    }
    cout << cnt << endl << EOF;
    return 0;
}
