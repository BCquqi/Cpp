void tarjan(int x,int pre) {
	dfn[x] = low[x] = ++idx;
	for (auto y : G[x]) {
		if (y == pre) continue;
		if (!dfn[y]) {
			tarjan(y,x);
			low[x] = min(low[x],low[y]);
			if (low[y] > dfn[x]) ans++;
		}
		else low[x] = min(low[x],dfn[y]);
	}
}