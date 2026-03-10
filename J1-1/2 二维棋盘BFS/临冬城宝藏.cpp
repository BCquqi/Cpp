#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int l,r,c;
char a[35][35][35];
int dis[35][35][35];
bool vis[35][35][35];
int sx,sy,sz,ex,ey,ez;
int dx[] = {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {0,0,0,0,1,-1};

struct Node {
	int x,y,z;
};

void bfs()
{
	queue<Node> q;
	q.push({sx,sy,sz});
	dis[sx][sy][sz] = 0;
	vis[sx][sy][sz] = true;
	while (q.size())
	{
		int x = q.front().x,y = q.front().y,z = q.front().z;
		q.pop();
		if (x == ex && y == ey && z == ez) return ;
		for (int i = 0;i < 6;i++)
		{
			int nx = x + dx[i],ny = y + dy[i],nz = z + dz[i];
			if (nx < 1 || nx > r || ny < 1 || ny > c || nz < 1 || nz > l) continue;
			if (a[nz][nx][ny] == '#') continue;
			if (vis[nx][ny][nz]) continue;
			q.push({nx,ny,nz});
			vis[nx][ny][nz] = true;
			dis[nx][ny][nz] = dis[x][y][z] + 1;
		}
	}
}

int main()
{
	cin >> l >> r >> c;
	for (int i = 1;i <= l;i++)
		for (int j = 1;j <= r;j++)
			for (int k = 1;k <= c;k++)
			{
				cin >> a[i][j][k];
				if (a[i][j][k] == 'S') sx = j,sy = k,sz = i;
				else if (a[i][j][k] == 'E') ex = j,ey = k,ez = i;
			}
	bfs();
	if (vis[ex][ey][ez]) cout << dis[ex][ey][ez] << endl;
	else cout << "Winter is Coming!" << endl;
	return 0;
}