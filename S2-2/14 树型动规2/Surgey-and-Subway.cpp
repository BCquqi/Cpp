#include<iostream>
#include<vector>
using namespace std;

const int N = 2e5 + 5;
vector<int> G[N];
int n;
long long ans1 = 0,ans2 = 0,siz[N],cnt1 = 0,cnt2 = 1,dep[N];

void dfs(int u,int pa) {
	siz[u] = 1;
	for (auto v : G[u]) {
		if (v == pa) continue;
		dep[v] = dep[u] + 1;
		dfs(v,u);
		siz[u] += siz[v];
		if (dep[v] % 2 == 0) cnt2++;
		else cnt1++;
		ans1 += (siz[v]) * (n - siz[v]);
	}
}

int main() {
	cin >> n;
	for (int i = 1;i < n;i++) {
		int u,v;
		cin >> u >> v;
		G[u].push_back(v); G[v].push_back(u);
	}
	dfs(1,0);
	ans2 += cnt1 * cnt2;
	cout << (ans1 + ans2) / 2 << endl;
	return 0;
}