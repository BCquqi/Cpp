#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;

const int N = 3e5 + 5;
vector<int> G[N];
int d[N],dis1[N],dis2[N];
bool flag[N];
int n,m,cnt;

void dfs(int u,int pa,int T) {
    dis1[u] = flag[u] ? 0 : -1e18,dis2[u] = 1e18;
    for (int v : G[u]) {
        if (v == pa) continue;
        dfs(v,u,T);
        dis1[u] = max(dis1[u],dis1[v] + 1), 
        dis2[u] = min(dis2[u],dis2[v] + 1);
    }
    if (dis1[u] != -1e18 && dis1[u] + dis2[u] <= T) dis1[u] = -1e18;
    if (dis2[u] > T && flag[u]) dis1[u] = max(dis1[u],0ll);
    if (dis1[u] == T) cnt++, dis2[u] = 0, dis1[u] = -1e18;
}

bool check(int mid) {
    cnt = 0;
    dfs(1,0,mid);
    if (dis1[1] >= 0) cnt++;
    return cnt <= m;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> d[i];
        flag[i] = d[i];
    }
    for (int i = 1;i < n;++i) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
    }
    int l = 0,r = n,ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}