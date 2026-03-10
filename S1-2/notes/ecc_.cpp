void tarjan(int x,int pre) { // 边双连通分量
	dfn[x] = low[x] = ++idx;
    st[++top] = x; // 初始化
    for (auto [y,i] : G[x]) { // 为防止有重边要在数组第二项增加边的编号
        if (i == pre) continue; // 访问回去了
        if (!dfn[y]) {
            tarjan(y,i); // 同时要把刚刚访问的边变成i
            low[x] = min(low[x],low[y]);
            if (low[y] > dfn[x]) bridge[i] = true; // 记录是桥
        }
        else low[x] = min(low[x],dfn[y]);
    }
    if (low[x] == dfn[x]) {
        int y;
        cnt_ecc++;
        do {
            y = st[top--];
            id[y] = cnt_ecc;
        } while (x != y);
    }
}