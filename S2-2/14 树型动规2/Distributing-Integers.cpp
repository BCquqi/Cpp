#include<iostream>
#include<vector>
using namespace std;

const int N = 2e5 + 5,mod = 1e9 + 7;
vector<int> G[N];
long long fact[N],ans[N],dp[N],siz[N],n;

long long qpow(long long a,long long b,long long p) {
    long long ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ret;
}

void dfs(int u,int pa) {
    siz[u] = 1,dp[u] = 1;
    for (auto v : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
        siz[u] += siz[v];
        dp[u] *= dp[v] * qpow(fact[siz[v]],mod - 2,mod) % mod;
        dp[u] %= mod;
    }
    dp[u] = dp[u] * fact[siz[u] - 1] % mod;
}

void dfs2(int u,int pa) {
    for (auto v : G[u]) {
        if (v == pa) continue;
        ans[v] = (ans[u] * siz[v]) % mod * qpow(n - siz[v],mod - 2,mod) % mod;
        dfs2(v,u);
    }
}

int main() {
    cin >> n;
    for (int i = 1;i < n;i++) {
        int a,b;
        cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    fact[0] = 1;
    for (int i = 1;i <= n;i++) fact[i] = fact[i - 1] * i % mod;
    dfs(1,0);
    ans[1] = dp[1];
    dfs2(1,0);
    for (int i = 1;i <= n;i++) cout << ans[i] << endl;
    return 0;
}