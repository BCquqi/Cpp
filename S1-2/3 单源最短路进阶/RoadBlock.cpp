#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int N = 205;
int G[N][N],dis[N],vis[N],f[N],n,m,ans = 0;

void dijkstra() {
	memset(dis,0x3f,sizeof dis);
	dis[1] = 0;
	for (int t = 1;t <= n;t++) {
		int u = 0;
		for (int i = 1;i <= n;i++)
			if (!vis[i] && dis[i] < dis[u]) u = i;
		vis[u] = true;
		for (int v = 1;v <= n;v++)
			if (G[u][v] && dis[v] > dis[u] + G[u][v])
				dis[v] = dis[u] + G[u][v],f[v] = u;
	}
	return ;
}

void dijkstra2() {
	memset(dis,0x3f,sizeof dis);
	memset(vis,false,sizeof vis);
	dis[1] = 0;
	for (int t = 1;t <= n;t++) {
		int u = 0;
		for (int i = 1;i <= n;i++)
			if (!vis[i] && dis[i] < dis[u]) u = i;
		vis[u] = true;
		for (int v = 1;v <= n;v++)
			if (G[u][v] && dis[v] > dis[u] + G[u][v])
				dis[v] = dis[u] + G[u][v];
	}
	return ;
}

int main() {
	cin >> n >> m;
	for (int i = 1;i <= m;i++) {
		int a,b,l;
		cin >> a >> b >> l;
		G[a][b] = G[b][a] = l;
	}
	dijkstra();
	int t = dis[n],u = n;
	while (u != 1) {
		int v = f[u];
		G[u][v] *= 2,G[v][u] *= 2;
		dijkstra2();
		ans = max(ans,dis[n] - t);
		G[u][v] /= 2,G[v][u] /= 2;
		u = v;
	}
	cout << ans << endl;
	return 0;
}