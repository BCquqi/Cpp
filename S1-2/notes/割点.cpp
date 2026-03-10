void tarjan(int x) {
	dfn[x] = low[x] = ++idx;
	bool flag = false;
	int child = 0;
	for (auto y : G[x]) {
		if (!dfn[y]) {
			child++;
			tarjan(y);
			low[x] = min(low[x],low[y]);
			if (low[y] >= dfn[x]) flag = true;
		}
		else low[x] = min(low[x],dfn[y]);
	}
	if (x == 1 && child < 2) flag = false;
	if (flag) ans++;
}