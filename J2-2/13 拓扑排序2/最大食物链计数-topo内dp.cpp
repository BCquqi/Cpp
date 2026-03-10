#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 5005,mod = 80112002;
vector<int> G[N];
int in[N],out[N],dp[N],tmp[N],n,m,ans = 0;
queue<int> q;

void topo_sort() {
	for (int i = 1;i <= n;i++)
		if (tmp[i] == 0) {
			dp[i] = 1;
			q.push(i);
		}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto v : G[u]) {
			dp[v] += dp[u];
			dp[v] %= mod;
			if (--tmp[v] == 0) q.push(v);
		}
	}
	return ;
}

int main() {
	cin >> n >> m;
	for (int i = 1;i <= m;i++) {
		int a,b;
		cin >> a >> b;
		G[b].push_back(a);
		in[a]++,tmp[a]++,out[b]++;
	}
	topo_sort();
	for (int i = 1;i <= n;i++)
		if (out[i] == 0) ans += dp[i],ans %= mod;
	cout << ans << endl;
	return 0;
}