#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int a[N],tree[N],cpy[N],n,ans = 0;

int lowbit(int x) {return x & -x;}
void add(int id,int val) {while (id <= n) {tree[id] += val,id += lowbit(id);}}
int query(int id) {
    int ret = 0;
    while (id) ret += tree[id],id -= lowbit(id);
    return ret;
}

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        cpy[i] = a[i];
    }
    sort(cpy + 1,cpy + n + 1);
    int len = unique(cpy + 1,cpy + n + 1) - cpy - 1;
    for (int i = 1;i <= n;i++) {
        a[i] = lower_bound(cpy + 1,cpy + len + 1,a[i]) - cpy; // 转化为下标
        add(a[i],1); // 离散化箱数组
        ans += i - query(a[i]); // 下标比 i 靠前但是值比 a[i] 大的都是逆序对
    }
    cout << ans << endl;
    return 0;
}