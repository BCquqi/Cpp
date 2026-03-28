#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int n,k,cnt = 0;
char a[105][15];
int vis[105][15],ans[1005];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void dfs(int x,int y)
{
	vis[x][y] = cnt;
	ans[cnt]++;
	for (int i = 0;i < 4;i++)
	{
		int nx = x + dx[i],ny = y + dy[i];
		if (nx < 1 || nx > n || ny < 1 || ny > 10) continue;
		if (a[x][y] != a[nx][ny]) continue;
		if (vis[nx][ny] > 0) continue;
		dfs(nx,ny);
	}
	return ;
}

bool check()
{
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= 10;j++)
			if (a[i][j] != '0' && !vis[i][j])
			{
				cnt++;
				dfs(i,j);
			}
	bool flag = true;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= 10;j++)
			if (ans[vis[i][j]] >= k) a[i][j] = '0',flag = false;
	return flag;
}

int main() {
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= 10;j++)
			cin >> a[i][j];
	while (true)
	{
		cnt = 0;
		memset(vis,0,sizeof vis);
		memset(ans,0,sizeof ans);
		if (check()) break;
		for (int j = 1;j <= 10;j++)
		{
			int x = n;
			for (int i = n;i >= 1;i--)
				if (a[i][j] != '0')
				{
					swap(a[i][j],a[x][j]);
					x--;
				}
		}
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= 10;j++)
			cout << a[i][j];
		cout << endl;
	}
    return 0;
}