#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const int N = 105;
int n,m,ans = 4,bit[130],vis[N][N];
char p[N][N],q[N][N];
struct Edge {int x,y,w;};
vector<Edge> G[N][N];

bool dfs(int a,int b,int c,int d,int mask) {
    if (a == c && b == d) return true;
    vis[a][b] = true;
    for (auto [x,y,w] : G[a][b]) {
        if ((mask & (1 << bit[w])) == 0) continue;
        if (vis[x][y]) continue;
        if (dfs(x,y,c,d,mask)) return true;
    }
    return false;
}

int main() {
    bit['P'] = 0,bit['C'] = 1,bit['Z'] = 2,bit['N'] = 3;
    // freopen("maze.in","r",stdin);
    // freopen("maze.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j < m;j++) {
            cin >> p[i][j];
            G[i][j].push_back({i,j + 1,p[i][j]});
            G[i][j + 1].push_back({i,j,p[i][j]});
        }
    for (int i = 1;i < n;i++)
        for (int j = 1;j <= m;j++) {
            cin >> q[i][j];
            G[i][j].push_back({i + 1,j,q[i][j]});
            G[i + 1][j].push_back({i,j,q[i][j]});
        }
    int Q;
    cin >> Q;
    while (Q--) {
        ans = 4;
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        for (int i = 0;i <= 15;i++) {
            memset(vis,0,sizeof vis);
            if (dfs(a,b,c,d,i))
                ans = min(ans,__builtin_popcount(i));
        }
        cout << ans << endl;
    }
    return 0;
}