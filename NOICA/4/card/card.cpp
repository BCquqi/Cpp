#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

bool check(int mid,int x,int y,int z) {
    if (mid == 0) return true;
    return 2 * mid + 1 <= x + y + z && mid - x <= mid / 2 && mid - y <= mid / 2 && mid - z <= mid / 2 && max(0ll,mid - x) + max(0ll,mid - y) + max(0ll,mid - z) < mid;
    // 总共牌数是 2 * mid + 1；
    // 最优策略的保留牌肯定不会连续两个花色一样，设其中保留牌数量 k，则 k < mid / 2 且 mid - k <= 牌数，变一下就是 mid - k <= mid / 2 了
    // 最后要保证三个颜色一起安排的下
}

void solve() {
    int x,y,z;
    cin >> x >> y >> z;
    int l = 0,r = (x + y + z - 1) / 2;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid,x,y,z)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
    return ;
}

signed main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}