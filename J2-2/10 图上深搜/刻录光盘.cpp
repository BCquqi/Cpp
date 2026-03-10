#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5 + 5;
vector<int> G[N];
bool vis[N];

void dfs(int u) {
	vis[u] = true;
	for (auto v : G[u])
		if (!vis[v]) dfs(v);
}

int main() {
	int n,m,ans = 0;
	cin >> n >> m;
	for (int i = 1;i <= m;i++) {
		int a,b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for (int i = 1;i <= n;i++)
		if (!vis[i]) {
			ans++;
			dfs(i);
		}
	cout << ans << endl;
	return 0;
}