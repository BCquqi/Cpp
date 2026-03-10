#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int N = 1005;
int a[N];
bool vis[N];
vector<int> rG[N];

void dfs(int u) {
	vis[u] = true;
	for (auto v : rG[u])
		if (!vis[v]) dfs(v);
}

int main() {
	int k,n,m,ans = 0;
	cin >> k >> n >> m;
	for (int i = 1;i <= k;i++) cin >> a[i];
	for (int i = 1;i <= m;i++) {
		int a,b;
		cin >> a >> b;
		rG[b].push_back(a);
	}
	for (int i = 1;i <= n;i++) {
		memset(vis,false,sizeof vis);
		dfs(i);
		bool flag = true;
		for (int j = 1;j <= k;j++) flag &= vis[a[j]];
		if (flag) ans++;
	}
	cout << ans << endl;
	return 0;
}