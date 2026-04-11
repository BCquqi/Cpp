void tarjan(int x) {
    dfn[x] = low[x] = ++idx;
    st[++top] = x;
    vis[x] = true;
    for (auto y : G[x]) {
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x],low[y]);
        }
        else if (vis[y]) low[x] = min(low[x],dfn[y]);
    }
    if (dfn[x] == low[x]) {
        cnt_scc++;
        int y;
        do {
            y = st[top--];
            vis[y] = false;
            id[y] = cnt_scc;
            siz[cnt_scc]++;
        } while (x != y);
    }
}