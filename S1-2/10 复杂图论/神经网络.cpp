#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 105;
int u[N],cur,in[N],topo[N],c[N],n,p,out[N];
struct Edge {int v,w;};
vector<Edge> G[N];

void topo_sort() {
	queue<int> q;
	for (int i = 1;i <= n;i++)
		if (in[i] == 0) q.push(i);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		topo[++cur] = u;
		for (auto [v,w] : G[u])
			if (--in[v] == 0) q.push(v);
	}
}

int main() {
	cin >> n >> p;
	for (int i = 1;i <= n;i++) cin >> c[i] >> u[i];
	for (int i = 1;i <= p;i++) {
		int u,v,w;
		cin >> u >> v >> w;
		G[u].push_back({v,w});
		in[v]++,out[u]++;
	}
	for (int i = 1;i <= n;i++)
		if (in[i]) c[i] = -u[i];
	topo_sort();
	for (int i = 1;i <= n;i++) {
		int u = topo[i];
		for (auto [v,w] : G[u])
			if (c[u] > 0) c[v] += w * c[u];
	}
	bool flag = false;
	for (int i = 1;i <= n;i++)
		if (out[i] == 0 && c[i] > 0) {cout << i << ' ' << c[i] << endl; flag = true;}
	if (!flag) cout << "NULL" << endl;
	return 0;
}