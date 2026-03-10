#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int n,m,t,sx,sy,ex,ey;
bool vis[10][10];
int dx[] = {0,0,-1,1},dy[] = {-1,1,0,0};
int a[10],ans = 0;

void dfs(int x,int y)
{
	if (x == ex && y == ey)
	{
		ans++;
		return ;
	}
	for (int i = 0;i < 4;i++)
	{
		int nx = x + dx[i],ny = y + dy[i];
		if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
		if (vis[nx][ny]) continue;
		vis[nx][ny] = true;
		dfs(nx,ny);
		vis[nx][ny] = false;
	}
	return ;
}

int main(){
	cin >> n >> m >> t;
	cin >> sx >> sy >> ex >> ey;
	vis[sx][sy] = true;
	for (int i = 1;i <= t;i++)
	{
		int x,y;
		cin >> x >> y;
		vis[x][y] = true;
	}
	dfs(sx,sy);
	cout << ans << endl;
	return 0;
}