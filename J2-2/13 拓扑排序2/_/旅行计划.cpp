#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 1e5 + 5;
vector<int> G[N];
queue<int> q;
int in[N],dp[N],cnt,n,m;

void topo_sort() {
	for (int i = 1;i <= n;i++)
		if (in[i] == 0) q.push(i);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto v : G[u]) {
			dp[v] = max(dp[v],dp[u] + 1);
			if (--in[v] == 0) q.push(v);
		}
	}
	return ;
}

int main() {
	cin >> n >> m;
	for (int i = 1;i <= m;i++) {
		int x,y;
		cin >> x >> y;
		G[x].push_back(y);
		in[y]++;
	}
	for (int i = 1;i <= n;i++)
		if (in[i] == 0) dp[i] = 1;
	topo_sort();
	for (int i = 1;i <= n;i++) cout << dp[i] << endl;
	return 0;
}