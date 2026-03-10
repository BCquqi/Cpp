#include<iostream>
using namespace std;

char a[105][105];
int dx[] = {-1,1,0,0,-1,-1,1,1};
int dy[] = {0,0,-1,1,1,-1,1,-1};
int m,n,ans = 0;
bool vis[105][105];

void dfs(int x,int y)
{
	vis[x][y] = true;
	for (int i = 0;i < 8;i++)
	{
		int nx = x + dx[i],ny = y + dy[i];
		if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
		if (a[nx][ny] == '.') continue;
		if (vis[nx][ny]) continue;
		dfs(nx,ny);
	}
	return ;
}

int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
		{
			cin >> a[i][j];
		}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			if (a[i][j] == 'W' && !vis[i][j])
			{
				dfs(i,j);
				ans++;
			}
	cout << ans << endl;
	return 0;
}