#include<iostream>
#include<cstring>
using namespace std;

const int N = 505;
char c[N][N];
int vis[N][N];
int n,m,X,Y,len = 0,M,ans;
int dx[] = {1,-1,0,0},dy[] = {0,0,1,-1};
bool flag = false;

void dfs(int x,int y,int cnt) {
	if (c[x][y] == 'S' && cnt >= 4) { // 可以成为环
		flag = true,ans = cnt;
		return ;
	}
	if (c[x][y] == 'S' && cnt >= 1 && cnt < 4) return ;
	if (flag) return ;
	if (cnt > M) return ;
	for (int i = 0;i < 4;i++) {
		int nx = x + dx[i],ny = y + dy[i];
		if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
		if (c[nx][ny] == '#') continue;
		if (vis[nx][ny]) continue;
		vis[nx][ny] = true;
		dfs(nx,ny,cnt + 1);
		vis[nx][ny] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++) {
			cin >> c[i][j];
			if (c[i][j] == 'S') X = i,Y = j;
			if (c[i][j] == '.') len++;
		}
	for (M = 4;M <= min(1200,len);M++) {
		dfs(X,Y,0);
		if (flag) break;
	}
	cout << (flag ? ans : -1) << '\n';
	return 0;
}