#include<iostream>
#define int long long
using namespace std;

const int N = 3e5 + 5;
int a[N];

signed main() {
    freopen("separate.in","r",stdin);
    freopen("separate.out","w",stdout);
    int n;
    cin >> n;
    int cnt = 0,ans = 1;
    bool flag = 1,chk = 1;
    for (int i = 1;i <= n;i++) {
        char c;
        cin >> c;
        a[i] = c - '0';
        chk &= !a[i];
        if (a[i] == 1 && a[i - 1] == 1) { // 一开始就不符合要求
            cout << 0 << endl;
            return 0;
        }
        if (a[i] == 0) cnt++;
        else {
            if (flag) { // 第一段 0
                cnt--, flag = false;
                if (cnt > 0 && cnt % 2 == 0) ans *= cnt / 2 + 1;
                ans %= 998244353;
            } else { // 中间段 0
                cnt -= 2;
                if (cnt > 0 && cnt % 2 == 0) ans *= cnt / 2 + 1;
                ans %= 998244353;
            }
            cnt = 0;
        }
    }
    // 结尾段 0
    cnt -= !chk, flag = false;
    if (cnt > 0 && cnt % 2 == 0) ans *= cnt / 2 + 1;
    ans %= 998244353;
    cout << ans << endl;
    return 0;
}