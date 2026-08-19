#include<iostream>
#define int long long
using namespace std;

const int N = 1e5 + 5;
int n,m,a[N],tr1[N],tr2[N];

int lowbit(int x) {return x & -x;}
void add(int id,int val,int tree[]) {while (id <= n) {tree[id] += val,id += lowbit(id);}}
int query(int id,int tree[]) {
    int ret = 0;
    while (id) ret += tree[id],id -= lowbit(id);
    return ret;
}

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        add(i,a[i],tr1);
        add(i,a[i] * i,tr2);
    }
    while (m--) {
        string s;
        cin >> s;
        if (s[0] == 'M') {
            int i,x;
            cin >> i >> x;
            add(i,x - a[i],tr1);
            add(i,(x - a[i]) * i,tr2);
            a[i] = x;
        } else {
            int i;
            cin >> i;
            cout << 1ll * (i + 1) * query(i,tr1) - query(i,tr2) << endl;
        }
    }
    return 0;
}