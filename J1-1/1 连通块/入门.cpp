#include<iostream>
using namespace std;

char a[25][25];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int m,n,ans = 0;
bool vis[25][25];

void dfs(int x,int y)
{
	vis[x][y] = true;
	ans++;
	for (int i = 0;i < 4;i++)
	{
		int nx = x + dx[i],ny = y + dy[i];
		if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
		if (a[nx][ny] == '#') continue;
		if (vis[nx][ny]) continue;
		dfs(nx,ny);
	}
	return ;
}

int main()
{
	cin >> m >> n;
	int tmpx,tmpy;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
		{
			cin >> a[i][j];
			if (a[i][j] == '@') tmpx = i,tmpy = j;
		}
	dfs(tmpx,tmpy);
	cout << ans << endl;
	return 0;
}