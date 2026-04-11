void tarjan(int x,int pre) { // 从pre这条边走到x
	dfn[x] = low[x] = ++idx;
	for (auto y : G[x]) {
		if (y == pre) continue; // 发现走到自己父节点导致low[y] = dfn[x], 需使用pre特判避免
		if (!dfn[y]) {
			tarjan(y,x);
			low[x] = min(low[x],low[y]);
			if (low[y] > dfn[x]) ans++;
		}
		else low[x] = min(low[x],dfn[y]);
	}
}