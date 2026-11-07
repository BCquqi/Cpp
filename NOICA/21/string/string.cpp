#include<iostream>
#define int long long
using namespace std;

const int N = 2e5 + 5;
int a[N],siz = 0,lst[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = '?' + s;
    int cnt = 1;
    for (int i = 2;i <= n;i++) {
        if (s[i] == s[i - 1]) cnt++;
        else a[++siz] = cnt, cnt = 1;
    }
    a[++siz] = cnt, cnt = 1;
    int now = 0;
    for (int i = siz;i >= 1;i--) {
        if (a[i] != 1) now = i;
        lst[i] = now;
    }
    int cur = 0,ans = 0,rcur = siz;
    while (cur <= siz) {
        if (a[cur] == 0) {
            cur++;
            continue;
        }
        if (a[cur] != 1) ans++, cur++;
        else {
            int last = lst[cur];
            while (last != 0 && a[last] <= 1) last = lst[cur] = lst[last];
            if (last == 0) {
                a[rcur]--;
                if (a[rcur] == 0)
                    lst[rcur] = lst[rcur + 1], rcur--;
            } else {
                a[last]--;
                if (a[last] == 1) lst[last] = lst[last + 1];
            }
            ans++, cur++;
        }
    }
    cout << ans << endl;
    return 0;
}