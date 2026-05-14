#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int N = 3e4 + 5;
vector<int> G[N];
int dfn[N],low[N],idx = 0,ans = 0;

void init() {
	for (int i = 1;i <= N;i++) G[i].clear();
	memset(dfn,0,sizeof dfn);
	memset(low,0,sizeof low);
	idx = 0,ans = 0;
}

void tarjan(int x,int pre) { // 从pre这条边走到x
	dfn[x] = low[x] = ++idx;
	for (auto y : G[x]) {
		if (y == pre) continue;
		if (!dfn[y]) {
			tarjan(y,x);
			low[x] = min(low[x],low[y]);
			if (low[y] > dfn[x]) ans++;
		}
		else low[x] = min(low[x],dfn[y]);
	}
}

int main() {
	while (true) {
		init();
		int m,n;
		cin >> m >> n;
		if (m == 0) break;
		for (int i = 1;i <= n;i++) {
			int a,b;
			cin >> a >> b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		tarjan(1,-1);
		cout << ans << endl;
	}
	return 0;
}