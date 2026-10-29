#include<iostream>
#include<algorithm>
#include<set>
#include<cstring>
using namespace std;

/*
构造一个 AB 序列使得若 A 代表 1，B 代表 -1，其前缀和从不为负
在此条件下要求在 m 对 [l,r] 范围内，必须在每个范围内安排至少一个 A
构造的 AB 序列应当是符合条件序列下字典序最小的
无法构造输出 -1
序列长度 10 ^ 5 量级
*/

/*
1 根据特殊性质，对于每个限制，若无交集则将 A 靠前排一定不劣
- 扩展至一般情况，按 左端点-右端点  排序，然后将 A 排在区间最左端
- 其中，左端点从大到小(这样如果区间有交集方便考虑)，右端点也从大到小(最先考虑相交)

2 根据题目要求，存在的 A 数量和存在的 B 数量是相等的
- 1 中产生的点是必要的点，没有更优策略让这些点不标记
  - 若点多于 n / 2 则直接判否
  - 等于 n / 2 要进行 O(n) 验证
  - 小于 n / 2 则贪心地从前面的空缺开始填，填完 O(n) 验证
- 剩下的就是填写 B 了，验证部分不难

3 根据数据范围，每个区间计算是否相交肯定不可行
- 用有序集合 S 维护已经选为 A 的位置。处理 [l,r] 时，查找 l 的 lower_bound 后判断简单

4 字典序的要求和卖家比买家先出现的贪心策略相吻合，无需额外考虑
*/

const int N = 2e5 + 5;
struct Node {int x,y;} a[N];
set<int> s;
bool flag[N];
int n,m;

bool check() {
    int sum = 0;
    for (int i = 1;i <= n;i++) {
        if (flag[i]) sum++;
        else sum--;
        if (sum < 0) return false;
    }
    return sum == 0;
}

inline void print() {
    for (int i = 1;i <= n;i++)
        cout << (flag[i] ? 'A' : 'B');
    cout << '\n';
}

void solve() {
    s.clear();
    memset(flag,false,sizeof flag);
    cin >> n >> m;
    for (int i = 1;i <= m;i++)
        cin >> a[i].x >> a[i].y;
    sort(a + 1,a + m + 1,[](Node p,Node q) {return p.x != q.x ? p.x > q.x : p.y > q.y;});
    for (int i = 1;i <= m;i++) {
        auto [l,r] = a[i];
        auto it = s.lower_bound(l);
        if (it != s.end() && *it <= r) continue;
        s.insert(l), flag[l] = true;
    }
    int tar = n / 2;
    if (s.size() > tar) {
        cout << -1 << '\n';
    } else if (s.size() == tar) {
        if (check()) print();
        else cout << -1 << '\n';
    } else {
        for (int i = 1,cnt = s.size();i <= n && cnt < tar;i++)
            if (!flag[i]) flag[i] = true, cnt++;
        if (check()) print();
        else cout << -1 << '\n';
    }
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}