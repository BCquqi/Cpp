#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

int n,m,x,y;
int dis[405][405];
bool vis[405][405];
int dx[] = {1,-1,1,-1,2,-2,2,-2};
int dy[] = {2,2,-2,-2,1,1,-1,-1};

struct Node {
	int x,y;
};

void bfs()
{
	queue<Node> q;
	q.push({x,y});
	dis[x][y] = 0;
	vis[x][y] = true;
	while (q.size())
	{
		int fx = q.front().x,fy = q.front().y;
		q.pop();
		for (int i = 0;i < 8;i++)
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

int main() {
	memset(dis,-1,sizeof dis);
	cin >> n >> m;
	cin >> x >> y;
	bfs();
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
			printf("%-5d",dis[i][j]);
		cout << endl;
	}
    return 0;
}