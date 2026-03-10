#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

const int N = 505;
int n,m,x,c[N],ans = 1e9,dis[N]; bool vis[N];
struct Edge {
	int v,l,c;
}; vector<Edge> G[N];

void spfa(int minc) {
	memset(dis,0x3f,sizeof dis);
	queue<int> q;
	q.push(1);
	dis[1] = 0,vis[1] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		vis[u] = 0;
		for (auto p : G[u]) {
			int v = p.v,l = p.l,c = p.c;
			if (c < minc) continue;
			if (dis[v] > dis[u] + l) {
				dis[v] = dis[u] + l;
				if (vis[v] == 0) q.push(v);
				vis[v] = 1;
			}
		}
	}
}

int main() {
	cin >> n >> m >> x;
	for (int k = 1;k <= m;k++) {
		int i,j,l;
		cin >> i >> j >> l >> c[k];
		G[i].push_back({j,l,c[k]}); G[j].push_back({i,l,c[k]});
	}
	for (int i = 1;i <= m;i++) {
		spfa(c[i]);
		ans = min(ans,dis[n] + x / c[i]);
	}
	cout << ans << endl;
 	return 0;
}