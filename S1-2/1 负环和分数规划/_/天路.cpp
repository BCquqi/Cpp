#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N = 7005;
const double eps = 1e-3;
struct Edge {int u,v,p;};
int f[N],n,m,vis[N],cnt[N];
double dis[N];
vector<Edge> G[N];

bool spfa(double mid) {
    for (int i = 0;i <= n;i++) dis[i] = -1e9;
    memset(vis,0,sizeof vis);
    memset(cnt,0,sizeof cnt);
    queue<int> q;
    q.push(0);
    dis[0] = 0,vis[0] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = 0;
        for (auto [v,V,P] : G[u])
            if (dis[v] < dis[u] + V - mid * P) {
                dis[v] = dis[u] + V - mid * P;
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                    if (++cnt[v] >= n) return true;
                }
            }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int x,y,v,p;
        cin >> x >> y >> v >> p;
        G[x].push_back({y,v,p});
    }
    for (int i = 1;i <= n;i++) G[0].push_back({i,0});
	double L = 0,R = 200,ans = -1;
	while (R - L >= eps) {
		double mid = (L + R) / 2;
	    if (spfa(mid)) {
	        ans = mid;
	        L = mid;
	    } else R = mid;
	}
    if (ans != -1) printf("%.1lf\n",ans);
    else cout << -1 << endl;
    return 0;
}