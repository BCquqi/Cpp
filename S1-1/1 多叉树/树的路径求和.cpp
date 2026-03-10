#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5 + 5;
int a[N],n,s,ans = 0,f[N],sum[N];
vector<int> G[N];

void dfs(int u,int pa) {
	f[u] = pa,sum[u] = sum[pa] + a[u];
	for (auto v : G[u]) {
		if (v == pa) continue;
		dfs(v,u);
	}
}

int main() {
	cin >> n >> s;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i < n;i++) {
		int u,v;
		cin >> u >> v;
		G[u].push_back(v); G[v].push_back(u);
	}
	dfs(1,0);
	for (int v = 1;v <= n;v++) {
		int u = v;
		while (sum[v] - sum[f[u]] < s && u != 0) u = f[u];
		if (sum[v] - sum[f[u]] == s) ans++;
	}
	cout << ans << endl;
	return 0;
}