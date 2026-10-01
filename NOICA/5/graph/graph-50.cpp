#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 3e5 + 5;
struct Edge {int v,w;};
vector<Edge> G[N];
int ans = 0;

void dfs(int u,int last,int len) {
    ans = max(ans,len);
    for (auto [v,w] : G[u]) {
        if (w <= last) continue;
        dfs(v,w,len + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("graph.in","r",stdin);
    freopen("graph.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int s,t,u;
        cin >> s >> t >> u;
        G[s].push_back({t,u});
    }
    for (int i = 1;i <= n;i++) dfs(i,0,0);
    cout << ans << endl;
    return 0;
}