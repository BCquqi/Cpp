#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int N = 1005;
vector<int> G[N];
int w[N],dep[N];
long long ans = 1e18;

void dfs(int u,int pa) {
	dep[u] = dep[pa] + 1;
	for (auto v : G[u]) {
		if (v == pa) continue;
		dfs(v,u);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		int u;
		cin >> w[i] >> u;
		if (u != 0) {G[u].push_back(i); G[i].push_back(u);}
	}
	for (int i = 1;i <= n;i++) {
		memset(dep,0,sizeof dep);
		dep[0] = -1;
		dfs(i,0);
		long long tmp = 0;
		for (int j = 1;j <= n;j++) tmp += 1ll * dep[j] * w[j];
		ans = min(ans,tmp);
	}
	cout << ans << endl;
	return 0;
}