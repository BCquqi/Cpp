#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

const int N = 1e6 + 5;
int a[N],dp[N][2],vis[N],rt; // i 可以限制 a[i] 
// dp[u][0/1] 表示以 u 为根的子树中选 / 不选 u 时最多能选的个数 
// vis[i] 用于记录 i 找环 / dfs 时是否访问过 

vector<int> G[N];

/*
基环树处理: 
环会导致 dp 循环，必须拆环；
拆环后丢失了原环两点互斥的约束，所以分「root 可选 / 不可选」两种情况各跑一次 dp 取最大。
*/ 

int dfs(int u,bool flag) { // flag 为 1 则删去边不选，为 0 则必选 
	vis[u] = true;
	int minn = 1e9;
	for (auto v : G[u]) {
		if (v == rt) continue;
		dfs(v,flag);
		dp[u][0] += max(dp[v][0],dp[v][1]);
		// 限制的子节点至少一个没有被投放 
		minn = min(minn,max(dp[v][0],dp[v][1]) - dp[v][0]);
	}
	dp[u][1] = 1 + dp[u][0] - minn;
	if (flag && u == a[rt]) dp[u][1] += minn;
	return max(dp[u][0],dp[u][1]);
}

int solve(int u) {
	memset(dp,0,sizeof dp);
	for (rt = u;!vis[rt];rt = a[rt]) vis[rt] = true;
	int tmp = dfs(rt,0);
	memset(dp,0,sizeof dp);
	dfs(rt,1);
	return max(tmp,dp[rt][0]);
}

int main() {
	int n,ans = 0;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		G[a[i]].push_back(i); // 建反图，即被限制指向限制的 
	} 
	for (int i = 1;i <= n;i++)
		if (!vis[i]) ans += solve(i);
	cout << ans << endl;
	return 0;
}
