#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

char a[55][55];
int dis[55][55];
bool vis[55][55];
int sx,sy,ex,ey;
int dx[] = {-1,1,0,0},dy[] = {0,0,-1,1};
int n,m;

struct Node {
	int x,y;
};

void bfs()
{
	queue<Node> q;
	q.push({sx,sy});
	dis[sx][sy] = 0;
	vis[sx][sy] = true;
	while (q.size())
	{
		int x = q.front().x,y = q.front().y;
		q.pop();
		if (x == ex && y == ey) return ;
		for (int i = 0;i < 4;i++)
		{
			int nx = x + dx[i],ny = y + dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			if (a[nx][ny] == '0') continue;
			if (vis[nx][ny]) continue;
			q.push({nx,ny});
			vis[nx][ny] = true;
			dis[nx][ny] = dis[x][y] + 1;
		}
	}
}

int main(){
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			cin >> a[i][j];
	cin >> sx >> sy >> ex >> ey;
	bfs();
	if (vis[ex][ey]) cout << dis[ex][ey] << endl;
	else cout << -1 << endl;
	return 0;
}