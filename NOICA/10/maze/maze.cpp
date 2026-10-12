#include<iostream>
#include<queue>
#include<cstring>
#define int long long
using namespace std;

const int N = 2005;
struct Point {int x,y;};
char mp[N][N];
int dis[N][N];
bool vis[N][N];
int dx[] = {1,-1,0,0},dy[] = {0,0,1,-1};
int n,m,k,t;
int sx,sy,tx,ty;
int ans = 1e9;

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
    memset(dis,0x3f,sizeof dis);
    vis[sx][sy] = true, dis[sx][sy] = 0;
    queue<Point> q1,q2;
    q1.push({sx,sy});
    while (!q1.empty() || !q2.empty()) {
        Point it;
        if (q1.empty()) it = q2.front(), q2.pop();
        else if (q2.empty()) it = q1.front(), q1.pop();
        else {
            auto [x1,y1] = q1.front();
            auto [x2,y2] = q2.front();
            if (dis[x1][y1] <= dis[x2][y2]) it = q1.front(), q1.pop();
            else it = q2.front(), q2.pop();
        }
        auto [x,y] = it;
        vis[x][y] = true;
        for (int i = 0;i < 4;i++) {
            int nx = x + dx[i],ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (mp[nx][ny] == '#') continue;
            if (vis[nx][ny]) continue;
            if (dis[x][y] + 1 < dis[nx][ny])
                dis[nx][ny] = dis[x][y] + 1, q1.push({nx,ny});
        }
        for (int i = -k;i <= k;i++)
        for (int j = -(k - abs(i));j <= k - abs(i);j++) {
            int nx = x + i,ny = y + j;
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (mp[nx][ny] == '#') continue;
            if (vis[nx][ny]) continue;
            if (dis[x][y] + t < dis[nx][ny])
                dis[nx][ny] = dis[x][y] + t, q2.push({nx,ny});
        }
    }
    cout << (dis[tx][ty] == 0x3f3f3f3f3f3f3f3f ? -1 : dis[tx][ty]) << endl;
    return 0;
}