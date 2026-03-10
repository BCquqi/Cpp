#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int n,m;
char mp[55][55];
int dx[] = {0,0,-1,1},dy[] = {-1,1,0,0};
bool vis[55][55];

void dfs(int x,int y)
{
	vis[x][y] = true;
	for (int i = 0;i < 4;i++)
	{
		int nx = x + dx[i],ny = y + dy[i];
		if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
		if (mp[nx][ny] == '#') continue;
		if (vis[nx][ny]) continue;
		dfs(nx,ny);
	}
	return ;
}

void solve()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			cin >> mp[i][j];
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			if (mp[i][j] == 'B')
				for (int k = 0;k < 4;k++)
				{
					int nx = i + dx[k],ny = j + dy[k];
					if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
					if (mp[nx][ny] == 'G') 
					{
						cout << "No" << endl;
						return ;
					}
					if (mp[nx][ny] == 'B') continue;
					mp[nx][ny] = '#';
				}
	memset(vis,false,sizeof vis);
	if (mp[n][m] != '#') dfs(n,m);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			if (mp[i][j] == 'G' && !vis[i][j])
			{
				cout << "No" << endl;
				return ;
			}
	cout << "Yes" << endl;
	return ;
}

int main(){
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}