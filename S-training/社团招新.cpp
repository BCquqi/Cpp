#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
int a[N][4],c1[N],c2[N],c3[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i][1] >> a[i][2] >> a[i][3];
    int cur1 = 0,cur2 = 0,cur3 = 0,ans = 0;
    for (int i = 1;i <= n;i++) {
        int maxn = max(a[i][1],max(a[i][2],a[i][3]));
        if (maxn == a[i][1]) c1[++cur1] = i, ans += a[i][1];
        else if (maxn == a[i][2]) c2[++cur2] = i, ans += a[i][2];
        else c3[++cur3] = i, ans += a[i][3];
    }
    if (cur1 > n / 2) {
        sort(c1 + 1,c1 + cur1 + 1,[](int x,int y){return a[x][1] - max(a[x][2],a[x][3]) < a[y][1] - max(a[y][2],a[y][3]);});
        int cur = 0;
        while (cur1 > n / 2) {
            int id = c1[++cur];
            ans -= a[id][1];
            ans += max(a[id][2],a[id][3]);
            cur1--;
        }
    } else if (cur2 > n / 2) {
        sort(c2 + 1,c2 + cur2 + 1,[](int x,int y){return a[x][2] - max(a[x][1],a[x][3]) < a[y][2] - max(a[y][1],a[y][3]);});
        int cur = 0;
        while (cur2 > n / 2) {
            int id = c2[++cur];
            ans -= a[id][2];
            ans += max(a[id][1],a[id][3]);
            cur2--;
        }
    } else if (cur3 > n / 2) {
        sort(c3 + 1,c3 + cur3 + 1,[](int x,int y){return a[x][3] - max(a[x][1],a[x][2]) < a[y][3] - max(a[y][1],a[y][2]);});
        int cur = 0;
        while (cur3 > n / 2) {
            int id = c3[++cur];
            ans -= a[id][3];
            ans += max(a[id][1],a[id][2]);
            cur3--;
        }
    }
    cout << ans << endl;
    return ;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}