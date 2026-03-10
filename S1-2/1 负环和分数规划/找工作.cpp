#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

const int N = 225;
int d,p,c,f,s,dis[N],vis[N],cnt[N];
struct Edge {int v,w;};
vector<Edge> G[N];

bool spfa() {
	memset(dis,-0x3f,sizeof dis);
	queue<int> q;
	q.push(s);
	dis[s] = d,vis[s] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		vis[u] = 0;
		for (auto p : G[u]) {
			int v = p.v,w = p.w;
			if (dis[v] < dis[u] + w) {
				dis[v] = dis[u] + w;
				if (!vis[v]) {
					q.push(v);
					vis[v] = true;
					if (++cnt[v] >= c) return true;
				}
			}
		}
	}
	return false;
}

int main() {
	cin >> d >> p >> c >> f >> s;
	for (int i = 1;i <= p;i++) {
		int a,b;
		cin >> a >> b;
		G[a].push_back({b,d});
	}
	for (int i = 1;i <= f;i++) {
		int j,k,t;
		cin >> j >> k >> t;
		G[j].push_back({k,d - t});
	}
	if (spfa()) cout << -1 << endl;
	else {
		int ans = -1e9;
		for (int i = 1;i <= c;i++) ans = max(ans,dis[i]);
		cout << ans << endl;
	}
	return 0;
}