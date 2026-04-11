dp1[x] = ...;
for (y : G[x]) {
    dp1[y] = dp1[x]...;
    dfs(y);
    dp2[x] = dp2[y]...;
}