#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

char a[1005][1005];
int vis[1005][1005];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
int n,m,cnt = 0;
int ans[1000005];

void dfs(int x,int y)
{
	vis[x][y] = cnt;
	ans[cnt]++;
	for (int i = 0;i < 4;i++)
	{
		int nx = x + dx[i],ny = y + dy[i];
		if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
		if (a[x][y] == a[nx][ny]) continue;
		if (vis[nx][ny] > 0) continue;
		dfs(nx,ny);
	}
	return ;
}

int main(){
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			cin >> a[i][j];
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			if (vis[i][j] == 0)
			{
				cnt++;
				dfs(i,j);
			}
	while (m--)
	{
		int i,j;
		cin >> i >> j;
		cout << ans[vis[i][j]] << endl;
	}
	return 0;
}
