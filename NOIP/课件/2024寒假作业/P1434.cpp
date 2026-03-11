#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int r,c;
int mp[105][105];
int f[105][105];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int dfs(int x,int y)
{
	if (f[x][y] != -1) return f[x][y];
	int maxn = 0;
	for (int i = 0;i < 4;i++)
	{
		int nx = x + dx[i],ny = y + dy[i];
		if (nx < 1 || nx > r || ny < 1 || ny > c) continue;
		if (mp[nx][ny] >= mp[x][y]) continue;
		maxn = max(maxn,dfs(nx,ny));
	}
	return f[x][y] = maxn + 1;
}

int main() {
	memset(f,-1,sizeof f);
	cin >> r >> c;
	for (int i = 1;i <= r;i++)
		for (int j = 1;j <= c;j++)
			cin >> mp[i][j];
	int ans = 0;
	for (int i = 1;i <= r;i++)
		for (int j = 1;j <= c;j++)
			ans = max(ans,dfs(i,j));
	cout << ans << endl;
    return 0;
}
