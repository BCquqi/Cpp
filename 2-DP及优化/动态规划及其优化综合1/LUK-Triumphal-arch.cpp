#include<iostream>
#include<vector>
using namespace std;

const int N = 3e5 + 5;
vector<int> G[N];
int son[N],dp[N],l,r;

// init 处理出子节点数量 
void init(int u,int pa) {
	for (auto v : G[u]) {
		if (v == pa) continue;
		son[u]++;
		init(v,u);
	}
	l = min(l,son[u]), r = max(r,son[u]);
	return ;
}

void dfs(int u,int pa,int mid) {
	dp[u] = son[u] - mid;
	for (auto v : G[u]) {
		if (v == pa) continue;
		dfs(v,u,mid);
		dp[u] += max(dp[v],0);
	}
	return ;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1;i < n;i++) {
		int u,v;
		cin >> u >> v;
		G[u].push_back(v); G[v].push_back(u);  
	}
	init(1,0);
	int mid = 0,ans = 0;
	while (l <= r) {
		mid = (l + r) >> 1;
		dfs(1,0,mid);
		if (dp[1] <= 0) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	cout << ans << endl;
	return 0;
}
