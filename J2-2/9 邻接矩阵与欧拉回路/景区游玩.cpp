#include<iostream>
#include<cstring>
using namespace std;

const int N = 25;
int G[N][N],vis[N],ans = 0,n,m;

void dfs(int u,int dis) {
	ans = max(ans,dis);
	for (int v = 1;v <= n;v++) {
		if (G[u][v] == -1) continue;
		if (vis[v]) continue;
		vis[v] = true;
		dfs(v,dis + G[u][v]);
		vis[v] = false;
	}
}

int main() {
	cin >> n >> m;
	memset(G,-1,sizeof G);
	for (int i = 1;i <= m;i++) {
		int a,b,c;
		cin >> a >> b >> c;
		G[a][b] = G[b][a] = c;
	}
	for (int i = 1;i <= n;i++) {
		vis[i] = true;
		dfs(i,0);
		vis[i] = false;
	}
	cout << ans << endl;
	return 0;
}