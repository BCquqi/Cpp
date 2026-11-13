#include<iostream>
#include<cstdio>
using namespace std;

void solve() {
    int n,mx = 0,last = 0;
    cin >> n;
    if (n == 1) {
        cin >> mx;
        if (mx == 1) cout << "shuji" << endl;
        else cout << "fengyi" << endl;
        return ;
    }
    for (int i = 1;i <= n;i++) {
        int x;
        cin >> x;
        if (x > mx) last = mx,mx = x;
        else if (x > last) last = x;
    }
    if (mx - last > 1) cout << "fengyi" << endl;
    else {
        if ((mx - n) & 1) cout << "fengyi" << endl;
        else cout << "shuji" << endl;
    }
    return ;
}

int main() {
    freopen("stone.in","r",stdin);
    freopen("stone.out","w",stdout);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}