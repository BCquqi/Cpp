#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5 + 5;

vector<int> G[N];

int ans = 0;

void dfs(int u,int pa) {
    int son = G[u].size();
    if (u != 1) son--;
    int tmp = 1;
    while (tmp <= son) ans++,tmp *= 2;
    ans += son;
	for (auto v : G[u]) {
		if (v == pa) continue;
		dfs(v,u);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1;i < n;i++) {
		int a,b;
		cin >> a >> b;
		G[a].push_back(b); G[b].push_back(a);
	}
	dfs(1,0);
	cout << ans << endl;
	return 0;
}