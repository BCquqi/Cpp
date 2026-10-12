#include<iostream>
using namespace std;

const int N = 3e6 + 5;
int b,a,n;
string s;
int q[N],ql,qr;

int main() {
    freopen("toy.in","r",stdin);
    freopen("toy.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> b >> a >> n >> s;
    s = ' ' + s;
    int l1 = 1,r1 = a;
    int l2 = 1,r2 = b;
    ql = 1;
    for (int i = 1;i <= b;i++) q[++qr] = i;
    for (int i = b + 1;i <= a;i++) {
        if (s[i] == '0') continue;
        q[++qr] = i, ql++;
    }
    long long ans = 0;
    while (true) {
        if (l2 == l1)
            ans += b, l2 = q[ql], r2 = q[qr];
        l1++, r1++;
        if (s[r1] != '0') q[++qr] = r1, ql++;
        ++ans;
        if (!(l1 <= l2 && r2 <= r1)) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        if (r1 == n) break;
    }
    if (r2 != n) ans += b;
    cout << ans << endl;
    return 0;
}