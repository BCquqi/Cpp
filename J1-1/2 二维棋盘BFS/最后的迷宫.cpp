#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int ex,ey,sx,sy;
int n,m;
int dx[] = {0,0,-1,1,1,-1,1,-1};
int dy[] = {-1,1,0,0,1,-1,-1,1};
int dis[1005][1005];
bool flag[1005][1005],vis[1005][1005];
int ans = -1;
char a[1005][1005];

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
		if (flag[x][y] == true)
		{
			ans = dis[x][y];
			return ;
		}
		for (int i = 0;i < 4;i++)
		{
			int nx = x + dx[i],ny = y + dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			if (a[nx][ny] == 'X') continue;
			if (vis[nx][ny]) continue;
			q.push({nx,ny});
			vis[nx][ny] = true;
			dis[nx][ny] = dis[x][y] + 1;
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			cin >> a[i][j];
	while (true)
	{
		 cin >> ex >> ey >> sx >> sy;
		 if (ex == 0) break;
		 memset(flag,false,sizeof flag);
		 memset(dis,-1,sizeof dis);
		 memset(vis,false,sizeof vis);
		 for (int i = 0;i < 8;i++)
		 {
		 	int nx = ex,ny = ey;
		 	while (1 <= nx && nx <= n && 1 <= ny && ny <= m && a[nx][ny] == 'O')
		 	{
		 		flag[nx][ny] = true;
		 		nx += dx[i],ny += dy[i];
		 	}
		 }
		 ans = -1;
		 bfs();
		 if (ans != -1) cout << ans << endl;
		 else cout << "Poor Harry" << endl;
	}
	return 0;
}