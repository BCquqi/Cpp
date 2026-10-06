#include<iostream>
#include<queue>
using namespace std;

const int N = 3005;
struct Point {int x,y;} a[N];
int dx[] = {1,-1,0,0},dy[] = {0,0,1,-1};
int dis[N][N],lab[N][N];
bool vis[N][N],flag[N][N];

int main() {
    freopen("boundary.in","r",stdin);
    freopen("boundary.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= k;i++) {
        cin >> a[i].x >> a[i].y;
        vis[a[i].x][a[i].y] = true, dis[a[i].x][a[i].y] = 0, lab[a[i].x][a[i].y] = i;
    }
    int Q;
    cin >> Q;
    for (int i = 1;i <= Q;i++) {
        int x,y;
        cin >> x >> y;
        flag[x][y] = true;
    }
    queue<Point> q;
    for (int i = 1;i <= k;i++) q.push(a[i]);
    while (!q.empty()) {
        auto [x,y] = q.front(); q.pop();
        for (int i = 0;i < 4;i++) {
            int nx = x + dx[i],ny = y + dy[i];
            if (nx > n || nx < 1 || ny > m || ny < 1) continue;
            if (flag[nx][ny]) continue;
            if (!vis[nx][ny]) {
                vis[nx][ny] = true, dis[nx][ny] = dis[x][y] + 1, lab[nx][ny] = lab[x][y];
                q.push({nx,ny});
                continue;
            }
            if (dis[nx][ny] == dis[x][y] + 1 && (lab[x][y] == -1 || lab[nx][ny] == -1 || lab[nx][ny] != lab[x][y])) lab[nx][ny] = -1;
        }
    }
    int ans = 0;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            if (!flag[i][j] && vis[i][j] && lab[i][j] == -1) ans++;
    cout << ans << endl;
    return 0;
}