#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N = 2e5 + 5;
int y[N],tree[N],n,ans1 = 0,ans2 = 0;

int lowbit(int x) {return x & -x;}
void add(int id,int val) {while (id <= n) {tree[id] += val,id += lowbit(id);}}
int query(int id) {
    int ret = 0;
    while (id) ret += tree[id],id -= lowbit(id);
    return ret;
}

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> y[i];
    for (int i = 1;i <= n;i++) {
        int tmp1 = query(y[i] - 1),tmp2 = i - tmp1 - 1;
        ans1 += tmp2 * (n - tmp2 - y[i]),ans2 += tmp1 * (y[i] - tmp1 - 1);
        add(y[i],1);
    }
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}