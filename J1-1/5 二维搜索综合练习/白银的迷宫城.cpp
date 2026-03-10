#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int n,m;
char mp[1005][1005];
int vis[1005][1005];
bool flag[1000005];
int dx[] = {-1,1,0,0},dy[] = {0,0,-1,1};
int ans[1000005];
int id = 1;

void dfs(int x,int y)
{
	vis[x][y] = id;
	ans[id]++;
	for (int i = 0;i < 4;i++)
	{
		int nx = x + dx[i],ny = y + dy[i];
		if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
		if (mp[nx][ny] == '*') continue;
		if (vis[nx][ny]) continue;
		dfs(nx,ny);
	}
	return ;
}

int main(){
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			cin >> mp[i][j];
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			if (mp[i][j] == '.' && vis[i][j] == 0)
			{
				id++;
				dfs(i,j);
			}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			if (mp[i][j] == '*')
			{
				int sum = 1;
				for (int k = 0;k < 4;k++)
				{
					int x = i + dx[k],y = j + dy[k];
					if (x < 1 || x > n || y < 1 || y > m) continue;
					if (flag[vis[x][y]]) continue;
					sum += ans[vis[x][y]];
					flag[vis[x][y]] = true;
				}
				for (int k = 0;k < 4;k++)
				{
					int x = i + dx[k],y = j + dy[k];
					if (x < 1 || x > n || y < 1 || y > m) continue;
					flag[vis[x][y]] = false;
				}
				cout << sum % 10;
			}
			else cout << '.';
		}
		cout << endl;
	}
	return 0;
}