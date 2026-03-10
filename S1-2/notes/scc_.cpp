// dfn代表其在图中的dfs序, low代表在第i个点的子节点中可回溯访问的dfn最小值(dfs序最靠前即连通分量最大)
void tarjan(int x) { // Tarjan模板
    dfn[x] = low[x] = ++idx;
    st[++top] = x; // 一般手写栈表示一个连通分量(dfs使用栈)
    vis[x] = true;
    for (auto y : G[x]) {
        if (!dfn[y]) { // 没有走到
            tarjan(y);
            low[x] = min(low[x],low[y]);
        }
        else if (vis[y]) low[x] = min(low[x],dfn[y]); // 目前处理的环中出现
    }
    if (dfn[x] == low[x]) { // 搜到后就弹出直到x(最上面的一个点)
        cnt_scc++;
        int y;
        do {
            y = st[top--];
            vis[y] = false;
            id[y] = cnt_scc;
            siz[cnt_scc]++;
        } while (x != y)
    }
}