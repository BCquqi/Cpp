#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N = 1e5 + 5;
struct Node {long long x,y;} a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("double.in","r",stdin);
    freopen("double.out","w",stdout);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
    sort(a + 1,a + n + 1,[](Node x,Node y) {return x.y < y.y;});
    int l = 1,r = n;
    long long ans = 0;
    while (l <= r) {
        while (l <= r && a[l].x == 0) l++;
        while (l <= r && a[r].x == 0) r--;
        if (l > r) break;
        if (l == r) {
            ans = max(ans,2 * a[l].y);
            break;
        }
        ans = max(ans,a[l].y + a[r].y);
        long long tmp = min(a[l].x, a[r].x);
        a[l].x -= tmp, a[r].x -= tmp;
    }
    cout << ans << endl;
    return 0;
}