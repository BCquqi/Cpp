#include<iostream>
#include<vector>
using namespace std;

const int N = 1e6 + 5;

struct Edge {
	int v,w;
};

vector<Edge> G[N];

int s[N],f[N];

void dfs(int u,int pa) {
	s[u] = 1;
	for (auto p : G[u]) {
		int v = p.v,w = p.w;
		if (v == pa) continue;
		f[v] = w;
		dfs(v,u);
		s[u] += s[v];
	}
}

int main() {
	int n;
	long long ans =  0;
	cin >> n;
	for (int i = 1;i < n;i++) {
		int a,b,c;
		cin >> a >> b >> c;
		G[a].push_back({b,c}); G[b].push_back({a,c});
	}
	dfs(1,0);
	for (int i = 1;i <= n;i++) ans += 1ll * f[i] * abs(s[i] - (n - s[i]));
	cout << ans << endl;
	return 0;
}