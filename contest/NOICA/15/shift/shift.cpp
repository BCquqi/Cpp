#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N = 1e6 + 5;
struct Node {int x,y;} a[N];

signed main() {
    freopen("shift.in","r",stdin);
    freopen("shift.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int c,T;
    cin >> c >> T;
    while (T--) {
        int n;
        cin >> n;
        int cur = 0;
        for (int i = 1;i <= n;i++) {
            int l,r,L,R;
            cin >> l >> r >> L >> R;
            int l1 = L - r;
            int r1 = min(L - l,R - r);
            if (l1 <= r1)
                a[++cur] = {l1,1}, a[++cur] = {r1 + 1,-1};
            int l2 = max(L - l,R - r) + 1;
            int r2 = R - l + 1;
            if (l2 <= r2)
                a[++cur] = {l2,-1}, a[++cur] = {r2 + 1,1};
        }
        if (cur == 0) {
            cout << 0 << ' ' << 0 << endl;
            continue;
        }
        sort(a + 1,a + cur + 1,[](Node p,Node q) {return p.x < q.x;});
        int now = 0,delta = 0,mx = -1,ans = 0,last = a[1].x;
        for (int i = 1;i <= cur;i++) {
            int cur = a[i].x;
            if (cur > last) {
                now += delta;
                if (now > mx) mx = now, ans = last;
                else if (now == mx && last < ans) ans = last;
                int tmp = now + delta * (cur - 1 - last);
                if (tmp > mx) mx = tmp, ans = cur - 1;
                else if (tmp == mx && cur - 1 < ans) ans = cur - 1;
                now = tmp;
            }
            delta += a[i].y;
            while (i + 1 <= cur && a[i + 1].x == cur)
                i++, delta += a[i].y;
            last = cur;
        }
        cout << mx << ' ' << ans << endl;
    }
    return 0;
}