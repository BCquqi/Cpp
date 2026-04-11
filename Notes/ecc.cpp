void tarjan(int x,int pre) {
	dfn[x] = low[x] = ++idx;
    st[++top] = x;
    for (auto [y,i] : G[x]) {
        if (i == pre) continue;
        if (!dfn[y]) {
            tarjan(y,i);
            low[x] = min(low[x],low[y]);
            if (low[y] > dfn[x]) bridge[i] = true;
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