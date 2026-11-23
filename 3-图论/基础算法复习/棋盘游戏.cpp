#include<iostream>
#include<cstring>
using namespace std;

const int N = 505;
int a[N][N];
struct pr {
    int a,b;
    bool operator == (pr x) {return a == x.a && b == x.b;}
    bool operator != (pr x) {return a != x.a || b != x.b;}
} dir[] = {{1,0},{-1,0},{0,1},{0,-1}},f[N][N];

pr find(int x1,int x2) {
    if ((pr){x1,x2} == f[x1][x2]) return {x1,x2};
    else return f[x1][x2] = find(f[x1][x2].a,f[x1][x2].b);
}

void merge(int x1,int y1,int x2,int y2) {
    auto f1 = find(x1,y1),f2 = find(x2,y2);
    if (f1 != f2) f[f1.a][f1.b] = {f2.a,f2.b};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n,m;
    cin >> n >> m;
    memset(a,-1,sizeof a);
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++) f[i][j] = {i,j};
    int ans = 0;
    while (m--) {
        int c,x,y;
        cin >> c >> x >> y;
        a[x][y] = c;
        ans++;
        bool diff = false;
        for (auto [dx,dy] : dir) {
            int nx = x + dx,ny = y + dy;
            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if (a[nx][ny] == c)
                if (find(x,y) != find(nx,ny))
                    f[find(x,y).a][find(x,y).b] = find(nx,ny), ans--;
        }
        cout << ans << '\n';
    }
    return 0;
}