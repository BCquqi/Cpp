#include<iostream>
#include<queue>
using namespace std;

const int N = 405;
char a[N][N];
bool vis[N][N];
int dx[] = {1,-1,0,0},dy[] = {0,0,1,-1};

struct Pos {int x,y;};

int main() {
    freopen("dun.in","r",stdin);
    freopen("dun.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n,m;
    cin >> n >> m;
    int sx = 0,sy = 0;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++) {
            cin >> a[i][j];
            if (a[i][j] == 'S') sx = i, sy = j;
        }
    queue<Pos> q;
    q.push({sx,sy}), vis[sx][sy] = true;
    int ans = 0;
    while (!q.empty()) {
        auto [x,y] = q.front(); q.pop();
        if (a[x][y] == 'o') ans++;
        for (int i = 0;i < 4;i++) {
            int nx = x + dx[i],ny = y + dy[i];
            if (vis[nx][ny]) continue;
            if (a[nx][ny] == '#' || a[nx][ny] == 'X') continue;
            vis[nx][ny] = true;
            q.push({nx,ny});
        }
    }
    cout << ans << '\n';
    return 0;
}