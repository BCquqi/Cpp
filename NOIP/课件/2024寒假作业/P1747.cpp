#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int dis[25][25];
bool vis[25][25];
int dx[] = {1,-1,1,-1,2,-2,2,-2,2,2,-2,-2};
int dy[] = {2,2,-2,-2,1,1,-1,-1,2,-2,2,-2};

struct Node {
	int x,y;
};

void bfs(int x,int y)
{
	queue<Node> q;
	q.push({x,y});
	dis[x][y] = 0;
	vis[x][y] = true;
	while (q.size())
	{
		int fx = q.front().x,fy = q.front().y;
		q.pop();
		if (fx == 1 && fy == 1) return;
		for (int i = 0;i < 12;i++)
		{
			int nx = fx + dx[i],ny = fy + dy[i];
			if (nx < 1 || nx > 20 || ny < 1 || ny > 20) continue;
			if (vis[nx][ny]) continue;
			q.push({nx,ny});
			vis[nx][ny] = true;
			dis[nx][ny] = dis[fx][fy] + 1;
		}
	}
}

int main()
{
	int x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	memset(dis,-1,sizeof dis);
	memset(vis,0,sizeof vis);
	bfs(x1,y1);
	cout << dis[1][1] << endl;
	memset(dis,-1,sizeof dis);
	memset(vis,0,sizeof vis);
	bfs(x2,y2);
	cout << dis[1][1] << endl;
	return 0;
}
