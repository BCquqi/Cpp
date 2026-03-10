#include<iostream>
#include<vector>
using namespace std;

const int N = 16005;
int a[N],s[N];
vector<int> G[N];

void dfs(int u,int pa) {
	s[u] = a[u];
	for (auto v : G[u]) {
		if (v == pa) continue;
		dfs(v,u);
		s[u] += max(s[v],0);
	}
}

int main() {
	int n,ans = -1e9;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i < n;i++) {
		int a,b;
		cin >> a >> b;
		G[a].push_back(b); G[b].push_back(a);
	}
	dfs(1,0);
	for (int i = 1;i <= n;i++) ans = max(ans,s[i]);
	cout << ans << endl;
	return 0;
}