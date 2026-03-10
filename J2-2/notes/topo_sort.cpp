void topo_sort() {
	for (int i = 1;i <= n;i++)
		if (in[i] == 0) q.push(i);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		topo[++cur] = u;
		for (auto v : G[u])
			if (--in[v] == 0) q.push(v);
	}
}