#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int N = 105;
vector<int> G[N],rG[N];
int vis[N],rvis[N];

int dfs(int u) {
	vis[u] = true;
	int ret = 1;
	for (auto v : G[u])
		if (!vis[v]) ret += dfs(v);
	return ret;
}

int rdfs(int u) {
	rvis[u] = true;
	int ret = 1;
	for (auto v : rG[u])
		if (!rvis[v]) ret += rdfs(v);
	return ret;
}

int main() {
	int n,m,ans = 0;
	cin >> n >> m;
	for (int i = 1;i <= m;i++) {
		int a,b;
		cin >> a >> b;
		G[a].push_back(b);
		rG[b].push_back(a);
	}
	for (int i = 1;i <= n;i++) {
		memset(vis,0,sizeof vis);
		memset(rvis,0,sizeof rvis);
		int cnt = dfs(i) + rdfs(i);
		if (cnt == n + 1) ans++;
	}
	cout << ans << endl;
	return 0;
}