#include<iostream>
#include<vector>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int N = 1005;
int dis[N],cnt[N],n,ml,md;
bool vis[N];
struct Edge {int v,w;};
vector<Edge> G[N];

bool spfa(int s) {
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	memset(cnt,0,sizeof cnt);
	queue<int> q;
	if (s == 0)
		for (int i = 1;i <= n;i++) {
			dis[i] = 0;
			vis[i] = cnt[i] = 1;
			q.push(i);
		}
	else {dis[s] = 0,vis[s] = 1; q.push(s);}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		vis[u] = false;
		for (auto [v,w] : G[u]) {
			if (dis[v] <= dis[u] + w) continue;
			dis[v] = dis[u] + w;
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
	cin >> n >> ml >> md;
	for (int i = 1;i <= ml;i++) {
		int a,b,d;
		cin >> a >> b >> d;
		G[a].push_back({b,d});
	}
	for (int i = 1;i <= md;i++) {
		int a,b,d;
		cin >> a >> b >> d;
		G[b].push_back({a,-d});
	}
	for (int i = 1;i < n;i++) G[i + 1].push_back({i,0});
	if (spfa(0)) cout << -1 << endl;
	else {
		spfa(1);
		if (dis[n] >= 1e9) cout << -2 << endl;
		else cout << dis[n] - dis[1] << endl;
	}
	return 0;
}