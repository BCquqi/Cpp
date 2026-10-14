#include<iostream>
#include<vector>
using namespace std;

const int N = 1005;
int a[N],ans = 0;
vector<int> G[N];

void dfs(int u,int pa) {
	ans++;
	for (auto v : G[u]) {
		if (!a[v]) continue;
		if (v == pa) continue;
		dfs(v,u);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i < n;i++) {
		int u,v;
		cin >> u >> v;
		G[u].push_back(v); G[v].push_back(u);
	}
	dfs(1,0);
	cout << ans << endl;
	return 0;
}