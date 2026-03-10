void LCA() { // 最近公共祖先朴素
    int x,y;
	cin >> x >> y;
	while (x != y) {
		if (x > y) x /= 2;
		else y /= 2;
	}
	cout << x << endl;
}

void first_search(int u) { // 先序遍历
	cout << u;
	if (l[u]) first_search(l[u]);
	if (r[u]) first_search(r[u]);
	return ;
}

void mid_search(int u) { // 中序遍历
    if (l[u]) mid_search(l[u]);
    cout << u;
    if (r[u]) mid_search(r[u]);
    return ;
}

void last_search(int u) { // 后序遍历
    if (l[u]) last_search(l[u]);
    if (r[u]) last_search(r[u]);
    cout << u;
    return ;
}

void bfs() { // 层次遍历
	queue<int> q;
	q.push(1);
	a[1].dep = 1;
	int cnt = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (a[u].dep != cnt) {cnt++; cout << endl;}
		cout << u << ' ';
		if (a[u].lch) {q.push(a[u].lch); a[a[u].lch].dep = a[u].dep + 1;}
		if (a[u].rch) {q.push(a[u].rch); a[a[u].rch].dep = a[u].dep + 1;}
	}
}