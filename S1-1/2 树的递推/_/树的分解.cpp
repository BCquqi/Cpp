#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int N = 1e5 + 5;
vector<int> G[N];
int dp[N],n,k,cnt = 0;

void dfs(int u,int pa) {
	dp[u] = 1;
	for (auto v : G[u]) {
		if (v == pa) continue;
		dfs(v,u);
		dp[u] += dp[v];
	}
	if (dp[u] == k) dp[u] = 0,cnt++;
}

void solve() {
	cnt = 0;
	for (int i = 1;i <= n;i++) G[i].clear();
	memset(dp,0,sizeof dp);
	cin >> n >> k;
	for (int i = 1;i < n;i++) {
		int a,b;
		cin >> a >> b;
		G[a].push_back(b); G[b].push_back(a);
	}
	if (n % k != 0) {
		cout << "NO" << endl;
		return ;
	}
	dfs(1,0);
	if (cnt == n / k) cout << "YES" << endl;
	else cout << "NO" << endl;
	return ;
}

int main() {
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}