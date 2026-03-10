bool vis[]; // 记录i是否在队列
int dis[]; // 记录起点到i的最短路
void spfa() {
	memset(dis,0x3f,sizeof dis);
	queue<int> q;
	q.push(s);
	dis[s] = 0,vis[x] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		vis[x] = 0;
		for (auto [v,w] : G[u]) {
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if (!vis[v]) q.push(y);
				vis[v] = 1;
			}
		}
	}
}