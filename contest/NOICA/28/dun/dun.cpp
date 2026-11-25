#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#define int long long 
using namespace std;

const int N = 405,M = 825;
int n,m,cnt = 0,x[65],y[65];
int o[M][M],w[M][M],b[M][M];
bool vis[M][M];
char a[N][N];
int ans = 1e18;
int dx[] = {-1,0,0,1},dy[] = {0,-1,1,0};

int check(int s,int u,int v) {
    u += N,v += N;
    for (int i = -1;i <= 1;i++)
        for (int j = -1;j <= 1;j++) {
            int p = o[u + i][v + j] & s;
            int q = w[u + i][v + j] & s;
            if (p && p != s) return p;
            if (q && q != s) return q;
        }
    return 0;
}

void bfs(int s) {
    vector<pair<int,int> > p;
    queue<pair<int,int> > q;
    int res = 0;
    q.push({0,0});
    p.push_back({0,0});
    vis[N][N] = true;
    while (!q.empty()) {
        auto [u,v] = q.front(); q.pop();
        int t = check(s,u,v);
        if (t) {
            for (auto [u,v] : p) vis[N + u][N + v] = false;
            vector<pair<int,int>>().swap(p);
            queue<pair<int,int>>().swap(q);
            bfs(t), bfs(s ^ t);
            return ;
        }
        if (o[N + u][N + v] & s) res++;
        for (int i = 0;i < 4;i++) {
            int nu = u + dx[i],nv = v + dy[i];
            if ((b[N + nu][N + nv] & s) || vis[N + nu][N + nv]) continue;
            q.push({nu,nv});
            p.push_back({nu,nv});
            vis[N + nu][N + nv] = true;
        }
    }
    for (auto [u,v] : p) vis[N + u][N + v] = false;
    ans = min(ans,res);
    return ;
}

signed main() {
    freopen("dun.in","r",stdin);
    freopen("dun.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++) {
            cin >> a[i][j];
            if (a[i][j] == 'S') cnt++,x[cnt] = i,y[cnt] = j;
        }
    for (int i = 1;i <= cnt;i++)
        for (int j = 1;j <= n;j++)
            for (int k = 1;k <= m;k++) {
                char c = a[j][k];
                int u = j + N - x[i],v = k + N - y[i];
                if (c == '#')
                    w[u][v] |= 1ll << i - 1,
                    b[u][v] |= 1ll << i - 1;
                else if (c == 'X')
                    b[u][v] |= 1ll << i - 1;
                else if (c == 'o')
                    o[u][v] |= 1ll << i - 1;
            }
    bfs((1ll << cnt) - 1);
    cout << ans << endl;
    return 0;
}