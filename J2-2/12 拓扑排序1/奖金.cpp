#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 1e4 + 5;
vector<int> G[N];
queue<int> q;
int n,m,in[N],dp[N];

void topo_sort() {
	for (int i = 1;i <= n;i++) {
		if (in[i] == 0) q.push(i);
		dp[i] = 100;
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto v : G[u]) {
			if (--in[v] == 0) q.push(v);
			dp[v] = max(dp[v],dp[u] + 1);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1;i <= m;i++) {
		int a,b;
		cin >> a >> b;
		G[b].push_back(a);
		in[a]++;
	}
	topo_sort();
    for (int i = 1;i <= n;i++)
        if (in[i] != 0) {
            cout << "Poor Xed" << endl;
            return 0;
        }
	int ans = 0;
	for (int i = 1;i <= n;i++) ans += dp[i];
	cout << ans << endl;
	return 0;
}
