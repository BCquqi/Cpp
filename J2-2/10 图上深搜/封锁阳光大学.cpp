#include<iostream>
#include<vector>
using namespace std;

const int N = 1e4 + 5;
vector<int> G[N];
int sum1 = 0,sum2 = 0,color[N];

bool dfs(int u,int c) {
	color[u] = c;
	if (c == 1) sum1++;
	else sum2++;
	for (auto v : G[u]) {
		if (color[v] == 0) {
			if (!dfs(v,-c)) return false;
		}
		else if (color[v] == c) return false;
	}
	return true;
}

int main() {
	int n,m,ans = 0;
	cin >> n >> m;
	for (int i = 1;i <= m;i++) {
		int u,v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 1;i <= n;i++)
		if (color[i] == 0) {
			sum1 = 0,sum2 = 0;
			if (!dfs(i,1)) {
				cout << "Impossible" << endl;
				return 0;
			}
			ans += min(sum1,sum2);
		}
	cout << ans << endl;
    return 0;
}