#include<cstdio>
#include<set>
#include<iostream>
#define int long long
using namespace std;

const int N = 2e5 + 5,mod = 998244353;
int n,m;
int s[N],f[N << 1],val[N << 1];
bool flag = true;

/*
1 取模象征着对于一个 s 的位，a 和 b 的状态是互相依赖的，即确定一个就能确定另一个

2 先事先确定可以判定的 a，对称位置一定相同；
  若能在其中一个确定 b，则 a 和 b 都是确定状态；

3 问题在于如何判定是否有解，即是否矛盾
- 并查集把共存的确定状态并在一起，那在合并时检查一下就知道矛不矛盾了

4 对于 a 和 b 可以拼起来，这样就是在同一个数组上做并查集操作
*/

int find(int x) {
    if (x != f[x]) {
        int tmp = f[x];
        f[x] = find(f[x]);
        val[x] ^= val[tmp];
    }
    return f[x];
}

bool merge(int x,int y,int w) {
    int fx = find(x),fy = find(y);
    if (fx == fy) return (val[x] ^ val[y]) == w;
    f[fy] = fx;
    val[fy] = val[x] ^ val[y] ^ w;
    return true;
}

int qpow(int a,int b) {
    int ret = 1 % mod;
    while (b) {
        if (b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

inline void add(int x,int y,int w) {if (!merge(x,y,w)) flag = false;}

void solve() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> s[i];
    flag = true;
    int len = n + m;
    for (int i = 0;i <= len;i++) f[i] = i,val[i] = 0;
    // 回文
    for (int i = 1;i <= n;i++) add(i,n - i + 1,0);
    for (int j = 1;j <= m;j++) add(n + j,n + (m - j + 1),0);
    for (int i = 1;i <= m;i++) // 绑定
        if (s[i] != -1) add(i,n + i,s[i]);
    for (int i = m + 1;i <= n;i++) // a 是常数
        if (s[i] != -1) add(i,0,s[i]);
    if (!flag) {
        cout << 0 << '\n';
        return ;
    }
    for (int i = 0;i <= len;i++) find(i);
    int ans = 0;
    for (int i = 0;i <= len;i++)
        if (f[i] == i) ans++;
    cout << qpow(2,ans - 1) << '\n';
    return ;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}