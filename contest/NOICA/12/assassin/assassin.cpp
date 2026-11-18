#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N = 1e5 + 5;
int a0[N],a1[N],a[N],s[N];
int cnt1,cnt2;

int calc(int x) {
    if (x <= 0) return 0;
    if (x <= cnt1 && a0[x] < a1[1])
        return s[x - 1] + a1[1];
    return s[x];
}

void solve() {
    int n,m;
    cin >> n >> m;
    cnt1 = cnt2 = 0;
    int wq = 0;
    for (int i = 0;i < n;i++) {
        int x,y;
        cin >> x >> y;
        if (y > 0) a1[++cnt2] = x, wq += y;
        else a0[++cnt1] = x;
    }
    sort(a0 + 1,a0 + cnt1 + 1);
    sort(a1 + 1,a1 + cnt2 + 1);
    int cur = 0;
    for (int i = 1;i <= cnt1;i++) a[++cur] = a0[i];
    for (int i = 1;i <= cnt2;i++) a[++cur] = a1[i];
    sort(a + 1,a + cur + 1);
    s[0] = 0;
    for (int i = 1;i <= cur;i++) s[i] = s[i - 1] + a[i];
    int sum = 0,tmp = 0;
    for (int i = 1;i <= cnt1;i++) {
        if (sum + a0[i] <= m) sum += a0[i],tmp++;
        else break;
    }
    int ans1 = tmp,ans2 = sum;
    if (cnt2 > 0) {
        int cost = max(1ll,cnt2 - wq);
        if (cost <= n) {
            int l = cost,r = n,mx = cost - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (calc(mid) <= m) mx = mid, l = mid + 1;
                else r = mid - 1;
            }
            if (mx >= cost)
                if (min(mx + wq,n) > ans1 || (min(mx + wq,n) == ans1 && calc((min(mx + wq,n) == n ? max(cost,n - wq) : mx)) < ans2))
                    ans1 = min(mx + wq,n), ans2 = calc((min(mx + wq,n) == n ? max(cost,n - wq) : mx));
        }
    }
    cout << ans1 << ' ' << ans2 << endl;
}

signed main() {
    freopen("assassin.in","r",stdin);
    freopen("assassin.out","w",stdout);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}