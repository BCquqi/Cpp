#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e3 + 5,mod = 1e9 + 7,M = 1e6 + 5;
int n,m,T;
char c[N][N];
bool flag[N][N];
int siz[N][N];
int dx[] = {1,-1,0,0},dy[] = {0,0,1,-1};
const int inv2 = 500000004,inv3 = 333333336,inv9 = 111111112;

struct Node {
    int x,y;
    bool operator == (Node p) const {return x == p.x && y == p.y;}
    bool operator != (Node p) const {return x != p.x || y != p.y;}
} f[N][N];

int qx[M],qy[M],ans[M];
long long tmp;

inline Node find(Node p) {return p == f[p.x][p.y] ? p : f[p.x][p.y] = find(f[p.x][p.y]);}

inline void merge(Node x,Node y) {
    Node fx = find(x),fy = find(y);
    if (fx != fy) {
        int s1 = siz[fx.x][fx.y],s2 = siz[fy.x][fy.y];
        if (s1 == 1 && s2 == 1) tmp = tmp * 2 % mod * inv9 % mod;
        else if (s1 == 1 || s2 == 1) tmp = tmp * inv3 % mod;
        else tmp = tmp * inv2 % mod;
        f[fx.x][fx.y] = fy;
        siz[fy.x][fy.y] += s1;
    }
    return ;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("zoo.in","r",stdin);
    freopen("zoo.out","w",stdout);
    cin >> n >> m >> T;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            cin >> c[i][j];
    for (int i = 1;i <= T;i++) {
        cin >> qx[i] >> qy[i];
        flag[qx[i]][qy[i]] = true;
    }
    tmp = 1;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++) {
            f[i][j] = {i,j};
            siz[i][j] = 1;
            if (c[i][j] == '?' && !flag[i][j]) tmp = tmp * 3 % mod;
        }
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++) {
            if (c[i][j] != '?' || flag[i][j]) continue;
            for (int k = 0;k < 4;k++) {
                int nx = i + dx[k],ny = j + dy[k];
                if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                if (c[nx][ny] != '?' || flag[nx][ny]) continue;
                merge({i,j},{nx,ny});
            }
        }
    ans[T] = tmp;
    for (int i = T;i >= 1;i--) {
        int x = qx[i],y = qy[i];
        flag[x][y] = false;
        tmp = tmp * 3 % mod;
        siz[x][y] = 1;
        for (int k = 0;k < 4;k++) {
            int nx = x + dx[k],ny = y + dy[k];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (c[nx][ny] != '?' || flag[nx][ny]) continue;
            merge({x,y},{nx,ny});
        }
        ans[i - 1] = tmp;
    }
    for (int i = 0;i <= T;i++)
        cout << ans[i] << endl;
    return 0;
}