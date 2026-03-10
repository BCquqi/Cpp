#include<iostream>
#include<deque>
#include<cstring>
using namespace std;

const int N = 1005;
int r,c,dis[N][N];
char a[N][N];
struct Node {int x,y;};
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

void bfs() {
    memset(dis,0x3f,sizeof dis);
    deque<Node> q;
    dis[1][1] = 0;
    q.push_back({1,1});
    while (!q.empty()) {
        Node p = q.front(); q.pop_front();
        int x = p.x,y = p.y;
        for (int i = 0;i < 4;i++) {
            int nx = x + dx[i],ny = y + dy[i],w;
            if (nx < 1 || nx > r || ny < 1 || ny > c) continue;
            if (a[x][y] == a[nx][ny]) w = 0;
            else w = 1;
            if (dis[nx][ny] > dis[x][y] + w) {
                dis[nx][ny] = dis[x][y] + w;
                if (w) q.push_back({nx,ny});
                else q.push_front({nx,ny});
            }
        }
    }
}

void solve() {
    cin >> r >> c;
    for (int i = 1;i <= r;i++)
        for (int j = 1;j <= c;j++)
            cin >> a[i][j];
    bfs();
    cout << dis[r][c] << endl;
    return ;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}