#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N = 1e5 + 5;
struct Node {int val,num;} a[N];

signed main() {
    freopen("discount.in","r",stdin);
    freopen("discount.out","w",stdout);
    int n,m,tot = 0;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i].num >> a[i].val;
        a[i].val %= m, tot += a[i].num * ((m - a[i].val) % m);
    }
    sort(a + 1,a + n + 1,[](Node x,Node y) {return x.val < y.val;});
    int l = 1,r = n;
    while (l <= n && a[l].val == 0) l++;
    int cnt = 0;
    while (l <= r) {
        if (l == r) {
            if (a[l].val * 2 <= m)
                cnt += a[l].num / 2;
            break;
        }
        if (a[l].val + a[r].val <= m) {
            int tmp = min(a[l].num,a[r].num);
            cnt += tmp, a[l].num -= tmp, a[r].num -= tmp;
            if (a[l].num == 0) l++;
            if (a[r].num == 0) r--;
        }
        else r--;
    }
    cout << tot - cnt * m << endl;
    return 0;
}