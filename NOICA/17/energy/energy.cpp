#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

/*
小朋友围成一圈，一次操作可以选择一个小朋友让他 -2，下一个 +1，问最少多少次操作可以让所有小朋友数字一样。
sum(n) <= 2e5
a[i] <= 1e9
T <= 20
*/

/*
预期复杂度 O(sum(n) log max(a[i]))
最终小朋友相等的能量值是可以二分枚举的，理由如下: 
若最终每人能量值是 x 可行，则每人能量值是 x - 1 也可行。
只需要从 x 的可行状态再让每个小朋友传递一圈即可。
而这样操作次数会多，所以小朋友的能量值肯定越大越好。
因此能量值是否可行严格满足单调性，且交接点最优。
*/

/*
对于检查该能量值是否可行：
0 这里可以预留的复杂度是 O(n)
1 首先，操作步数是可以确定的，也就是 sum(a[i]) - t * n
- 原因是每次操作会使得总和 - 1
2 很明显的是，对于 > t 的项目，一定要不断减到 < t。
- 所以简单的思路是对每一个项目不断减，这样跑几轮之后就可以结束了。
- 预估的轮次数量不超过 10^2，或许也不超过 10，理论上是可以过的。
- 你说得对，但是赛场上的我没有任何能力给出复杂度正确的证明。
- 赌一把吧！！！
*/

const int N = 2e5 + 5;
int n,a[N],cpy[N],sum = 0;

inline int nxt(int i) {return i == n ? 1 : i + 1;}

bool check(int t) {
    for (int i = 1;i <= n;i++) cpy[i] = a[i];
    int cnt = 0,step = sum - t * n;
    if (step < 0) return false;
    // cnt 记录连续有多少个比目标小的
    // step 记录要执行的次数
    for (int i = 1;step > 0;i = nxt(i)) {
        if (cpy[i] < t) cnt++;
        else cnt = 0;
        if (cnt >= n) return false; // 剪枝

        if (cpy[i] > t) {
            int diff = (cpy[i] - t + 1) / 2;
            step -= diff, cpy[i] -= diff * 2, cpy[nxt(i)] += diff;
        }
    }
    for (int i = 1;i <= n;i++)
        if (cpy[i] != t) return false;
    return true;
}

void solve() {
    sum = 0;
    cin >> n;
    int l = 0,r = 0,ans = 1e18;
    for (int i = 1;i <= n;i++)
        cin >> a[i], r = max(r,a[i]), sum += a[i];
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) l = mid + 1, ans = sum - mid * n;
        else r = mid - 1;
    }
    cout << (ans == 1e18 ? -1 : ans) << endl;
    return ;
}

signed main() {
    freopen("energy.in","r",stdin);
    freopen("energy.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}