#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
vector<int> G[N];
queue<int> q;
bool vis[N];

void dfs(int u) {
	vis[u] = true;
	cout << u << ' ';
	for (auto v : G[u])
		if (!vis[v]) dfs(v);
}

void bfs() {
	memset(vis,0,sizeof vis);
	q.push(1);
	vis[1] = true;
	cout << 1 << ' ';
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = true;
		for (auto v : G[u])
			if (!vis[v]) {
				q.push(v);
				vis[v] = true;
				cout << v << ' ';
			}
	}
}

int main() {
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= m;i++) {
		int x,y;
		cin >> x >> y;
		G[x].push_back(y);
	}
	for (int i = 1;i <= n;i++) sort(G[i].begin(),G[i].end());
	dfs(1);
	cout << endl;
	bfs();
	return 0;
}