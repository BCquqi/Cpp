#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

const int N = 20,M = (1 << 15) + 5,mod = 1e9 + 7;
int mp[M],st[M],tr[M][4],f[M],g[M],ans[N],cur = 0;
string s;
int n,m;

int nxt(int mask,char c) {
    int a = 0,b = 0,cur = 0;
    for (int k = 1;k <= n;k++) {
        int x = a + (mask >> (k - 1) & 1);
        int y = max(b,max(x,a + (s[k] == c)));
        if (y > b) cur |= 1 << (k - 1);
        a = x, b = y;
    }
    return cur;
}

void solve() {
    memset(mp,-1,sizeof mp), memset(f,0,sizeof f), memset(ans,0,sizeof ans);
    cin >> s >> m;
    n = s.size(), s = '?' + s;
    cur = 0;
    queue<int> q;
    mp[0] = 0, st[cur++] = 0, q.push(0);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto i : "ACGT") {
            int v = nxt(u,i);
            if (mp[v] == -1) mp[v] = cur++, st[cur - 1] = v, q.push(v);
        }
    }
    for (int i = 0;i < cur;i++)
        for (int j = 0;j < 4;j++)
            tr[i][j] = mp[nxt(st[i],"ACGT"[j])];
    f[0] = 1;
    while (m--) {
        memset(g,0,sizeof g);
        for (int i = 0;i < cur;i++)
            for (int j = 0;j < 4;j++)
                g[tr[i][j]] = (g[tr[i][j]] + f[i]) % mod;
        for (int i = 0;i < cur;i++) f[i] = g[i];
    }
    for (int i = 0;i < cur;i++) {
        int cnt = __builtin_popcount(st[i]);
        ans[cnt] = (ans[cnt] + f[i]) % mod;
    }
    for (int i = 0;i <= n;i++) cout << ans[i] << endl;
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}