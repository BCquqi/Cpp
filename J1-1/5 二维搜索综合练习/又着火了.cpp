#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int n,m,k,x,y;
bool vis[2005][2005];
int dis[2005][2005];
int dx[] = {0,0,-1,1},dy[] = {-1,1,0,0};

struct Node {
	int x,y;
};

queue<Node> q;

void bfs()
{
	while (q.size())
	{
		int fx = q.front().x,fy = q.front().y;
		q.pop();
		for (int i = 0;i < 4;i++)
		{
			int nx = fx + dx[i],ny = fy + dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			if (vis[nx][ny]) continue;
			q.push({nx,ny});
			vis[nx][ny] = true;
			dis[nx][ny] = dis[fx][fy] + 1;
		}
	}
}

int main(){
	cin >> n >> m;
	cin >> k;
	for (int i = 1;i <= k;i++)
	{
		cin >> x >> y;
		dis[x][y] = 0;
		vis[x][y] = true;
		q.push({x,y});
	}
	bfs();
	int ans = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			ans = max(ans,dis[i][j]);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			if (dis[i][j] == ans) cout << i << ' ' << j << endl;
	return 0;
}