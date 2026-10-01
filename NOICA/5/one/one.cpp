#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N = 1e5 + 5;
int a[N],n,m;

bool check(int mid) {
    // 排序结束后，想要完全覆盖，就要步步都踩在点子上
    int cur = 0;
    for (int i = 1;i <= m;i++) {
        cur += mid;
        // 检验: 必须覆盖到这个点
        if (cur < a[i]) return false; // 太晚
        if (cur > a[i] + mid - 1) cur = a[i] + mid - 1; // 过早，必须退回
    }
    if (cur < n) return false; // 到最后也无法覆盖
    return true;
}

signed main() {
    freopen("one.in","r",stdin);
    freopen("one.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= m;i++) cin >> a[i];
    sort(a + 1,a + m + 1); // 交换操作顺序不影响结果
    // 满足单调性
    int l = 1,r = n,ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}