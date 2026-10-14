#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 1e6 + 5;
vector<int> G[N],ans;
int dp[N],n;

void dfs(int u,int pa) {
	dp[u] = 1;
	bool flag = true;
	int tmp = 0;
	for (auto v : G[u]) {
		if (v == pa) continue;
		dfs(v,u);
		dp[u] += dp[v];
		if (tmp == 0) tmp = dp[v];
		else if (tmp != dp[v]) flag = false;
	}
	if (tmp != 0 && dp[u] != n && n - dp[u] != tmp) flag = false;
	if (flag) ans.push_back(u);
}

int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u,v;
		cin >> u >> v;
		G[u].push_back(v); G[v].push_back(u);
	}
	dfs(1,0);
	sort(ans.begin(),ans.end());
	for (auto i : ans) cout << i << ' ';
	cout << endl;
	return 0;
}