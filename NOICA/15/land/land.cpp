#include<iostream>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;

const int N = 1e5 + 5;
int a[N],ad[N],mi[N],n,h;
vector<int> G[N];

void dfs(int u,int pa) {
    int mx = 0,mn = 0;
    for (auto v : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
        mx = max(mx,ad[v]), mn = min(mn,mi[v]);
    }
    int k = (h - a[u]) - (mx + mn);
    if (k > 0) ad[u] = mx + k, mi[u] = mn;
    else ad[u] = mx, mi[u] = mn + k;
    return ;
}

signed main() {
    freopen("land.in","r",stdin);
    freopen("land.out","w",stdout);
    cin >> n >> h;
    for (int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
    }
    for (int i = 1;i <= n;i++) cin >> a[i];
    dfs(1,0);
    cout << ad[1] - mi[1] << endl;
    return 0;
}