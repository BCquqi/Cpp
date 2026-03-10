void bfs(int s) {
	memset(vis,0,sizeof vis);
    memset(dis,0x3f,sizeof dis);
	q.push(s);
	vis[s] = true,dis[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : G[u])
			if (!vis[v]) {
				q.push(v);
				vis[v] = true;
                dis[v] = dis[u] + 1;
			}
	}
}