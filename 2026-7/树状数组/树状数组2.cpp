#include<iostream>
#define int long long
using namespace std;

const int N = 1e6 + 5;
int a[N],tree[N],n,q;

int lowbit(int x) {return x & -x;}
void add(int id,int val) {while (id <= n) tree[id] += val,id += lowbit(id);}
int query(int id) {
    int ret = 0;
    while (id) ret += tree[id],id -= lowbit(id);
    return ret;
}

signed main() {
    cin >> n >> q;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        add(i,a[i] - a[i - 1]);
    }
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l,r,x;
            cin >> l >> r >> x;
            add(l,x);
            add(r + 1,-x);
        } else {
            int i;
            cin >> i;
            cout << query(i) << endl;
        }
    }
    return 0;
}