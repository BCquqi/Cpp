#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int N =  2e3 + 5;
int cnt[N],dis[N],vis[N],n,m;
struct Edge {int v,w;};
vector<Edge> G[N];

bool spfa() {
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	queue<int> q;
	q.push(1);
	dis[1] = 0,vis[1] = true;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		vis[u] = false;
		for (auto p : G[u]) {
			int v = p.v,w = p.w;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if (!vis[v]) {
					q.push(v);
					vis[v] = true;
					if (++cnt[v] >= n) return true;
				}
			}
		}
	}
	return false;
}

void solve() {
	memset(cnt,0,sizeof cnt);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) G[i].clear();
	for (int i = 1;i <= m;i++) {
		int u,v,w;
		cin >> u >> v >> w;
		if (w >= 0) {G[u].push_back({v,w}); G[v].push_back({u,w});}
		else G[u].push_back({v,w});
	}
	cout << (spfa() ? "YES" : "NO") << endl;
	return ;
}

int main() {
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}