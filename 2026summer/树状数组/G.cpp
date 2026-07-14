#include<iostream>
using namespace std;

const int N = 1e5 + 5;
int a[N],ans[N],n,tree[N];

int lowbit(int x) {return x & -x;}
void add(int id,int val) {while (id <= n) {tree[id] += val,id += lowbit(id);}}
int query(int id) {
    int ret = 0;
    while (id) ret += tree[id],id -= lowbit(id);
    return ret;
}

int main() {
    cin >> n;
    for (int i = 2;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++) add(i,1);
    for (int i = n;i >= 1;i--) {
        int l = 1,r = n;
        while (l <= r) {
            int mid = l + r >> 1;
            if (query(mid) > a[i]) r = mid - 1;
            else l = mid + 1;
        }
        ans[i] = l;
        add(l,-1);
    }
    for (int i = 1;i <= n;i++) cout << ans[i] << endl;
    return 0;
}