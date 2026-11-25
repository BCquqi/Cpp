#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 2e5 + 5;
int a[N],cnt[N],s[N];

int main() {
    freopen("nofe.in","r",stdin);
    freopen("nofe.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }
    int maxn = 0,scmx = 0;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        cnt[a[i]]++;
        if (a[i] >= maxn) scmx = maxn, maxn = a[i];
        else if (a[i] > scmx) scmx = a[i];
    }
    sort(a + 1,a + n + 1);
    for (int i = 1;i <= maxn;i++) s[i] = s[i - 1] + cnt[i];
    long long ans = 0;
    for (int v = 0;v <= floor(sqrt(maxn + scmx));v++) { // the value of [SQRT(a[i] + a[j])]
        for (int i = 1;i <= n && a[i] < (v + 1) * (v + 1) - 1;i++) { // the index i
            int l = v * v - a[i],r = (v + 1) * (v + 1) - 1 - a[i]; // the range of a[j]
            if (l > maxn) continue;
            l = max(l,1), r = min(r,maxn);
            ans += 1ll * (s[r] - s[l - 1]) * v;
            if (l <= a[i] && a[i] <= r) ans -= v;
        }
    }
    cout << ans / 2 << '\n';
    return 0;
}