#include<iostream>
#include<vector>
using namespace std;

const int N = 2e5 + 5,mod = 10007;

vector<int> G[N];

int w[N],f[N];

void dfs(int u,int pa) {
	f[u] = pa;
	for (auto v : G[u]) {
		if (v == pa) continue;
		dfs(v,u);
	}
}

int main() {
	int n;
	long long ansmax = 0,anssum = 0;
	cin >> n;
	for (int i = 1;i < n;i++) {
		int u,v;
		cin >> u >> v;
		G[u].push_back(v); G[v].push_back(u);
	}
	for (int i = 1;i <= n;i++) cin >> w[i];
	dfs(1,0);
	for (int u = 1;u <= n;u++) {
		int max1 = 0,max2 = 0,s = 0;
		for (auto v : G[u]) {
			if (w[v] > max1) max2 = max1,max1 = w[v];
			else if (w[v] > max2) max2 = w[v];
			s += w[v],s %= mod;
		}
		ansmax = max(ansmax,1ll * max1 * max2);
		ansmax = max(ansmax,1ll * w[u] * w[f[f[u]]]);
		for (auto v : G[u]) {
			if (v == f[u]) continue;
			anssum += 1ll * w[v] * (s - w[v]),anssum %= mod;
		}
		anssum += 1ll * w[u] * w[f[f[u]]],anssum %= mod;
	}
	cout << ansmax << ' ' << anssum << endl;
	return 0;
}