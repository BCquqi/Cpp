#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 3e5 + 5;
struct Edge {int u,v,w;} edge[N];
int dp[N],cur = 0,cpy[N];

int main() {
    freopen("graph.in","r",stdin);
    freopen("graph.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int s,t,u;
        cin >> s >> t >> u;
        edge[++cur] = {s,t,u};
    }
    sort(edge + 1,edge + cur + 1,[](Edge x,Edge y) {return x.w < y.w;});
    int j = 0;
    for (int i = 1;i <= cur;i = j + 1) {
        j = i;
        while (edge[j + 1].w == edge[i].w) ++j;
        for (int k = i;k <= j;k++) cpy[edge[k].u] = dp[edge[k].u], cpy[edge[k].v] = dp[edge[k].v];
        for (int k = i;k <= j;k++) dp[edge[k].v] = max(dp[edge[k].v],cpy[edge[k].u] + 1);
    }
    int ans = 0;
    for (int i = 1;i <= n;i++) ans = max(ans,dp[i]);
    cout << ans << endl;
    return 0;
}