#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int N = 1e5 + 5;
int a[N],dp[N],in[N],n,m,ans = -1e9;
vector<int> G[N];
queue<int> q;

void topo_sort() {
	for (int i = 1;i <= n;i++)
		if (in[i] == 0) q.push(i);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto v : G[u]) {
			dp[v] = max(dp[v],dp[u] + a[v]);
			if (--in[v] == 0) q.push(v);
		}
	}
}

int main() {
	memset(dp,-0x3f,sizeof dp);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	dp[1] = a[1];
	for (int i = 1;i <= m;i++) {
		int x,y;
		cin >> x >> y;
		G[x].push_back(y);
		in[y]++;
	}
	topo_sort();
	for (int i = 1;i <= n;i++) ans = max(ans,dp[i]);
	cout << ans << endl;
	return 0;
}