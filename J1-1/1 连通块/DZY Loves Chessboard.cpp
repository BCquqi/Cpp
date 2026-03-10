#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int n,m;
char a[105][105];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void dfs(int x,int y,char c)
{
	a[x][y] = c;
	for (int i = 0;i < 4;i++)
	{
		int nx = x + dx[i],ny = y + dy[i];
		if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
		if (a[nx][ny] != '.') continue;
		if (c == 'W') dfs(nx,ny,'B');
		else dfs(nx,ny,'W');
	}
	return ;
}

int main(){
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			cin >> a[i][j];
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			if (a[i][j] == '.') dfs(i,j,'B');
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
			cout << a[i][j];
		cout << endl;
	}
	return 0;
}