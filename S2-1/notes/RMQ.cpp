lg[1] = 0;
for (int i = 2;i <= n;i++) lg[i] = lg[i / 2] + 1;
for (int i = 1;i <= n;i++) st[i][0] = a[i];
for (int j = 1;j <= lg[n];j++)
    for (int i = 1;i + (1 << j) - 1 <= n;i++)
        st[i][j] = max(st[i][j - 1],st[i + (1 << j - 1)][j - 1]);
while (m--) {
    int k = lg[r - l + 1];
    cout << max(st[l][k],st[r - (1 << k) + 1][k]) << endl;
}