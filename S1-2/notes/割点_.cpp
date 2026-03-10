// 数组含义可以当做scc的含义理解
void tarjan(int x) {
	dfn[x] = low[x] = ++idx;
	bool flag = false; // 是否是割点
	int child = 0; // 特判是否是树根的割点用,记录有几个儿子(只有儿子数量为2根节点才是割点)
	for (auto y : G[x]) {
		if (!dfn[y]) {
			child++;
			tarjan(y);
			low[x] = min(low[x],low[y]);
			if (low[y] >= dfn[x]) flag = true; // 是割点
		}
		else low[x] = min(low[x],dfn[y]); // 这行不可以像scc那样可以写min(low[x],dfn[y])
	}
	if (x == 1 && child < 2) flag = false; // 是特殊的(不是割点的)根节点
	if (flag) ans++;
}