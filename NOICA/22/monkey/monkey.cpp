#include<iostream>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;

const int N = 1e6 + 5,mod = 998244353;
int p[N],up[N],down[N],c1[N],c2[N];
int n,ans;

int lowbit(int x) {return x & -x;}

inline void add(int id,int val,int c[]) {
    while (id <= n)
        c[id] = (c[id] + val) % mod,id += lowbit(id);
    return ;
}

inline int query(int id,int c[]) {
    int ret = 0;
    while (id) ret = (ret + c[id]) % mod,id -= lowbit(id);
    return ret;
}

void solve() {
    memset(c1,0,sizeof c1), memset(c2,0,sizeof c2);
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> p[i];
    ans = 0;
    int s1 = 0,s2 = 0;
    for (int i = n;i >= 1;i--) {
        down[i] = (query(p[i] - 1,c1) + 1) % mod, 
        up[i] = (s2 - query(p[i],c2) + 1 + mod) % mod, 
        ans = (ans + up[i] * down[i]) % mod;
        add(p[i],up[i],c2), add(p[i],down[i],c1);
        s1 = (s1 + down[i]) % mod, s2 = (s2 + up[i]) % mod;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("monkey.in","r",stdin);
    freopen("monkey.out","w",stdout);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}