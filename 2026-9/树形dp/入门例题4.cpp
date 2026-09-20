#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int N = 1e5 + 5;
struct Edge {int v,w;};
vector<Edge> G[N];
int f[N][2];

void dfs(int u,int pa) {
    f[u][0] = f[u][1] = 0;
    for (auto [v,w] : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
        if (f[v][0] + w > f[u][1])
            f[u][1] = f[v][0] + w;
        if (f[u][1] > f[u][0])
            swap(f[u][1],f[u][0]);
    }
    return ;
}

void solve() {
    memset(f,0,sizeof f);
    for (int i = 1;i < N;i++) G[i].clear();
    int n,s;
    cin >> n >> s;
    for (int i = 1;i < n;i++) {
        int x,y,z;
        cin >> x >> y >> z;
        G[x].push_back({y,z}); G[y].push_back({x,z});
    }
    dfs(s,0);
    for (int i = 1;i <= n;i++) cout << f[i][0] << ' ';
    cout << endl;
    for (int i = 1;i <= n;i++) cout << f[i][1] << ' ';
    cout << endl;
    return ;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}