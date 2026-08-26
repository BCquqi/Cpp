#include<iostream>
#include<vector>
#define int long long
using namespace std;

const int N = 2e4 + 5;
int n,s[N],t[N],a[N],b[N],c[N];
vector<vector<int> > dp[2 * N];

int dfs(int u,int ls,int rs,int depth) {
    if (u < 0) {
        int id = -u;
        return c[id] * (a[id] + ls) * (b[id] + rs);
    }
    if (dp[u].empty())
        dp[u].assign(depth + 1,vector<int>(depth + 1,-1));
    if (dp[u][ls][rs] != -1) return dp[u][ls][rs];
    int tmp1 = dfs(s[u],ls + 1,rs,depth + 1) + dfs(t[u],ls,rs,depth + 1);
    int tmp2 = dfs(s[u],ls,rs,depth + 1) + dfs(t[u],ls,rs + 1,depth + 1);
    return dp[u][ls][rs] = min(tmp1,tmp2);
}

signed main() {
    cin >> n;
    for (int i = 1;i < n;i++)
        cin >> s[i] >> t[i];
    for (int i = 1;i <= n;i++)
        cin >> a[i] >> b[i] >> c[i];
    cout << dfs(1,0,0,1) << endl;
    return 0;
}