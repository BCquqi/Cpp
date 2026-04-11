// 朴素
void dijkstra() {
	memset(dis,0x3f,sizeof dis);
	dis[s] = 0;
	for (int i = 1;i <= n;i++) {
		int u = 0;
		for (int j = 1;j <= n;j++)
			if (!vis[j] && dis[j] < dis[u]) u = j;
		vis[u] = true;
		for (auto [v,w] : G[u])
			dis[v] = min(dis[v],dis[u] + w);
	}
}

// 优先队列优化
struct Node {int v,w;};
bool operator < (const Node &x,const Node &y) {return x.w > y.w;}

void dijkstra() {
	memset(dis,0x3f,sizeof dis);
	priority_queue<Node> q;
	dis[s] = 0;
	q.push({s,dis[s]});
	while (!q.empty()) {
		int u = q.top().v; q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto [v,w] : G[u]) {
			if (vis[v]) continue;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push({v,dis[v]});
			}
		}
	}
}