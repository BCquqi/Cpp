#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<cstdio>
using namespace std;

const int N = 1005;
const double eps = 1e-4;
struct Edge {int v,w;};
int f[N],cnt[N],vis[N],l,p;
double dis[N];
vector<Edge> G[N];

bool spfa(double mid) {
	for (int i = 0;i <= l;i++) dis[i] = -1e9;
    memset(vis,0,sizeof vis);
    memset(cnt,0,sizeof cnt);
    queue<int> q;
    q.push(0);
    dis[0] = 0,vis[0] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = 0;
        for (auto p : G[u]) {
            int v = p.v,w = p.w;
            if (dis[v] < dis[u] + f[v] - mid * w) {
                dis[v] = dis[u] + f[v] - mid * w;
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                    if (++cnt[v] >= l) return true;
                }
            }
        }
    }
    return false;
}

int main() {
	cin >> l >> p;
	for (int i = 1;i <= l;i++) cin >> f[i];
	for (int i = 1;i <= p;i++) {
		int l1,l2,t;
		cin >> l1 >> l2 >> t;
		G[l1].push_back({l2,t});
	}
    for (int i = 1;i <= l;i++) G[0].push_back({i,0});
	double L = 0,R = 1e6,ans = 0;
	while (R - L >= eps) {
		double mid = (L + R) / 2;
	    if (spfa(mid)) {
	        ans = mid;
	        L = mid;
	    } else R = mid;
	}
	printf("%.2lf",ans);
	return 0;
}