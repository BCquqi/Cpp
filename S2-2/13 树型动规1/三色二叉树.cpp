#include<iostream>
#include<cstring>
using namespace std;

const int N = 5e5 + 5;
string s;
int id = 0,L[N],R[N],cur = 0,dp[N][2],dp2[N][2];

int build() {
    if (cur >= s.size()) return 0;
    int u = ++id;
    char c = s[cur++];
    if (c == '0')
        L[u] = R[u] = 0;
    else if (c == '1') {
        L[u] = build();
        R[u] = 0;
    } else {
        L[u] = build();
        R[u] = build();
    }
    return u;
}

void dfs(int u) {
    if (u == 0) return ;
    if (L[u]) dfs(L[u]);
    if (R[u]) dfs(R[u]);
    int lc = L[u],rc = R[u];
    if (L[u] == 0 && R[u] == 0) {
        dp[u][0] = 0,dp[u][1] = 1;
        dp2[u][0] = 0,dp2[u][1] = 1;
    } else if (R[u] == 0) {
        dp[u][0] = max(dp[lc][1],dp[lc][0]),dp[u][1] = 1 + dp[lc][0];
        dp2[u][0] = min(dp2[lc][1],dp2[lc][0]),dp2[u][1] = 1 + dp2[lc][0];
    } else {
        dp[u][1] = 1 + dp[lc][0] + dp[rc][0],dp[u][0] = max(dp[lc][1] + dp[rc][0],dp[lc][0] + dp[rc][1]);
        dp2[u][1] = 1 + dp2[lc][0] + dp2[rc][0],dp2[u][0] = min(dp2[lc][1] + dp2[rc][0],dp2[lc][0] + dp2[rc][1]);
    }
}

int main() {
    memset(dp2,0x3f,sizeof dp2);
    cin >> s;
    int root = build();
    dfs(1);
    cout << max(dp[1][0],dp[1][1]) << ' ' << min(dp2[1][0],dp2[1][1]) << endl;
    return 0;
}