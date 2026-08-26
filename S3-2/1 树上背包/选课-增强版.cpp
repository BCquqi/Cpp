#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5 + 5;
int n,m,sc[N],dp[N][305],siz[N];
vector<int> G[N];
// dp[i][j] 表示以 i 为根的子树中，选课数量为 j 的最大学分

void init(int u,int pa) {
	dp[u][1] = sc[u];
	siz[u] = 1;
	for (auto v : G[u]) {
		if (v == pa) continue;
		init(v,u);
		siz[u] += siz[v];
	}
}

void dfs(int u,int pa) {
    for (auto v : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
        for (int j = min(siz[u],m);j >= 1;j--)
            for (int k = 0;k <= min(j - 1,siz[v]);k++)
                dp[u][j] = max(dp[u][j],dp[u][j - k] + dp[v][k]);
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> n >> m;
    m++;
    for (int i = 1;i <= n;i++) {
        int u;
        cin >> u >> sc[i];
        G[u].push_back(i); G[i].push_back(u);
    }
    init(0,-1);
    dfs(0,-1);
    cout << dp[0][m] << endl;
    return 0;
}