#include<cstdio>
#include<iostream>
#include<algorithm>
#include<deque>
#include<cstring>
using namespace std;

const int N = 1005;
struct Node {int x,y;};
bool G[N][N][5];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int dis[N][N],x1,y1,x2,y2,n,r;

void bfs() {
	memset(dis,0x3f,sizeof dis);
	deque<Node> q;
	q.push_front({x1,y1});
	dis[x1][y1] = 0;
	while (!q.empty()) {
		Node u = q.front(); q.pop_front();
		int x = u.x,y = u.y;
		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i],ny = y + dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
			bool w = G[x][y][i];
			if (dis[nx][ny] > dis[x][y] + w) {
				dis[nx][ny] = dis[x][y] + w;
				if (w == 1) q.push_back({nx,ny});
				else q.push_front({nx,ny});
			}
		}
	}
}

int main() {
	cin >> n >> r;
	for (int i = 1;i <= r;i++) {
		int r1,c1,r2,c2;
		cin >> r1 >> c1 >> r2 >> c2;
		if (r1 == r2 && c1 == c2 + 1)
			G[r1][c1][0] = G[r2][c2][1] = true;
		else if (r1 == r2 && c2 == c1 + 1)
			G[r1][c1][1] = G[r2][c2][0] = true;
		else if (r1 == r2 + 1 && c1 == c2)
			G[r1][c1][2] = G[r2][c2][3] = true;
		else G[r1][c1][3] = G[r2][c2][2] = true;
	}
	cin >> x1 >> y1 >> x2 >> y2;
	bfs();
	cout << dis[x2][y2] << endl;
	return 0;
}