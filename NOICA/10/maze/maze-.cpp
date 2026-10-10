#include<iostream>
#define int long long
using namespace std;

const int N = 2005;
char mp[N][N];
bool vis[N][N];
int dx[] = {1,-1,0,0},dy[] = {0,0,1,-1};
int n,m,k,t;
int sx,sy,tx,ty;
int ans = 1e9;

void dfs(int x,int y,int dis) {
    if (x == tx && y == ty) {
        ans = min(ans,dis);
        return ;
    }
    for (int i = 0;i < 4;i++) {
        int nx = x + dx[i],ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if (mp[nx][ny] == '#') continue;
        if (vis[nx][ny]) continue;
        vis[nx][ny] = true;
        dfs(nx,ny,dis + 1);
        vis[nx][ny] = false;
    }
    for (int i = -k;i <= k;i++)
        for (int j = -(k - abs(i));j <= k - abs(i);j++) {
            int nx = x + i,ny = y + j;
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (mp[nx][ny] == '#') continue;
            if (vis[nx][ny]) continue;
            vis[nx][ny] = true;
            dfs(nx,ny,dis + t);
            vis[nx][ny] = false;
        }
}

signed main() {
    freopen("maze.in","r",stdin);
    freopen("maze.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k >> t;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++) {
            cin >> mp[i][j];
            if (mp[i][j] == 'S') sx = i, sy = j;
            if (mp[i][j] == 'T') tx = i, ty = j;
        }
    vis[sx][sy] = true;
    dfs(sx,sy,0);
    cout << ans << endl;
    return 0;
}