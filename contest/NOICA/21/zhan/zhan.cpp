#include<iostream>
#include<cstring>
using namespace std;

const int N = 3e5 + 5;
int a[N],cnt[N];
long long s[N];

void solve() {
    memset(cnt,0,sizeof cnt);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++)
        cin >> a[i], cnt[a[i]]++;
    s[0] = cnt[0];
    for (int i = 1;i <= n;i++) s[i] = s[i - 1] + cnt[i];
    long long ans = 0;
    for (int i = 0;i <= n;i++)
        if (cnt[i] >= 2)
            ans += 1ll * cnt[i] * (cnt[i] - 1) / 2 * (i == 0 ? 0 : s[i - 1]), 
            ans += 1ll * cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
    cout << ans << endl;
}

int main() {
    freopen("zhan.in","r",stdin);
    freopen("zhan.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}