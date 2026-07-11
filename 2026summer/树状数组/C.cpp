#include<iostream>
#define int long long
using namespace std;

const int N = 1e6 + 5;
int a[N],tree1[N],tree2[N],n,q;

int lowbit(int x) {return x & -x;}
void add(int id,int val,int tree[]) {while (id <= n) tree[id] += val,id += lowbit(id);}
int query(int id,int tree[]) {
    int ret = 0;
    while (id) ret += tree[id],id -= lowbit(id);
    return ret;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        add(i,a[i] - a[i - 1],tree1);
        add(i,(a[i] - a[i - 1]) * (i - 1),tree2);
    }
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l,r,x;
            cin >> l >> r >> x;
            add(l,x,tree1); add(r + 1,-x,tree1);
            add(l,(l - 1) * x,tree2); add(r + 1,-r * x,tree2);
        } else {
            int l,r;
            cin >> l >> r;
            cout << (r * query(r,tree1) - query(r,tree2)) - ((l - 1) * query(l - 1,tree1) - query(l - 1,tree2)) << '\n';
        }
    }
    return 0;
}