void dfs(int x,int y)
{
	vis[x][y] = true;
	ans++;
	for (int i = 0;i < 4;i++)
	{
		int nx = x + dx[i],ny = y + dy[i];
		if (nx < 1 || nx > n || ny < 1 || ny > n) continuel
		if (a[nx][ny] = '#') continue;
		if (vis[nx][ny]) continue;
		dfs(nx,ny);
	}
	return ;
}

struct Node {
	int x,y;
};

void bfs()
{
	queue<Node> q;
	q.push({sx,sy});
	vis[sx][sy] = true;
	dis[sx][sy] = 0;
	while (!q.empty())
	{
		int x = q.front().x,y = q.front().y;
		q.pop();
		if (x == ex && y == ey) return ;
		for (int i = 0;i < 4;i++)
		{
			int nx = x + dx[i],ny = y + dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > n) continuel
			if (a[nx][ny] = '#') continue;
			if (vis[nx][ny]) continue;
			q.push({nx,ny});
			vis[nx][ny] = true;
			dis[nx][ny] = dis[x][y] + 1;
		}
	}
}

bool check(int x)
{
	for (int i = 1;i <= x;i++)
	{
		for (int j = i + 1;j <= x;j++)
		{
			if (a[i] == a[j]) return false;
			if (abs(a[i] - a[j]) == abs(i - j)) return false;
		}
	}
	return true;
}

void dfs(int step)
{
	if (cnt >= k) return ;
	if (step > n)
	{
		cnt++;
		for (int i = 1;i <= n;i++) cout << a[i] << ' ';
		cout << endl;
		return ;
	}
	for (int i = 1;i <= n;i++)
	{
		if (vis[i]) continue;
		a[step] = i;
		if (!check(step)) continue;
		vis[i] = true;
		dfs(step + 1);
		a[step] = 0;
		vis[i] = false;
	}
}