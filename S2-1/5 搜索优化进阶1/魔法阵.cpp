#include<iostream>
#include<algorithm>
using namespace std;

const int N = 55;
int n,m,k1,k2,vis[N][N],ans = 1e9;
int dx[] = {0,0,-1,1},dy[] = {-1,1,0,0};
struct Node {int x,y;} pos[N];

void dfs(int x,int y,int id,int maxn) {
	if (maxn > ans) return ;
	if (vis[x - 1][y] && vis[x + 1][y] && !vis[x][y - 1] && !vis[x][y + 1]) return ;
	if (!vis[x - 1][y] && !vis[x + 1][y] && vis[x][y - 1] && vis[x][y + 1]) return ;
	pos[id] = {x,y};
	if (id >= n * m / 2) {
		int i = id - n * m / 2;
		int t = k1 * abs(x - pos[i].x) + k2 * abs(y - pos[i].y);
		if (t > maxn) maxn = t;
	}
	if (id == n * m - 1) {
		ans = min(ans,maxn);
		return ;
	}
	vis[x][y] = true;
	for (int i = 0;i <= 3;i++) {
		int nx = x + dx[i],ny = y + dy[i];
		if (vis[nx][ny]) continue;
		dfs(nx,ny,id + 1,maxn);
	}
	vis[x][y] = false;
}

int main() {
	cin >> n >> m >> k1 >> k2;
	for (int i = 1;i <= n;i++) vis[i][0] = vis[i][m + 1] = 1;
	for (int i = 1;i <= m;i++) vis[0][i] = vis[n + 1][i] = 1;
	dfs(1,m,0,0);
	cout << ans << endl;
	return 0;
}