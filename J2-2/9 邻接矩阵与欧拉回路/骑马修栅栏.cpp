#include<iostream>
using namespace std;

const int N = 505;
int G[N][N],deg[N],ans[1028],cur;

void dfs(int u) {
	for (int v = 1;v <= 500;v++)
		if (G[u][v]) {
			G[u][v]--,G[v][u]--;
			dfs(v);
		}
	ans[++cur] = u;
}

int main() {
	int m,cnt = 0;
	cin >> m;
	for (int i = 1;i <= m;i++) {
		int u,v;
		cin >> u >> v;
		G[u][v]++,G[v][u]++;
		deg[u]++,deg[v]++;
	}
	for (int u = 1;u <= 500;u++)
		if (deg[u] % 2) {
			dfs(u);
			cnt++;
			break;
		}
	if (cnt == 0)
		for (int u = 1;u <= 500;u++)
			if (deg[u] != 0) {
				dfs(u);
				break;
			}
	for (int i = cur;i >= 1;i--) cout << ans[i] << endl;
	return 0;
}