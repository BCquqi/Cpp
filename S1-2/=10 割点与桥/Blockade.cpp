#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5 + 5;
vector<int> G[N];
long long siz[N],ans[N],dfn[N],low[N],idx = 0;
int n,m;

void tarjan(int x) {
	dfn[x] = low[x] = ++idx;
	siz[x] = 1;
	bool flag = false;
	int child = 0,ss = n - 1;
	for (auto y : G[x]) {
		if (!dfn[y]) {
			tarjan(y);
			child++;
			siz[x] += siz[y];
			low[x] = min(low[x],low[y]);
			if (low[y] >= dfn[x]) flag = true,ans[x] += 1ll * siz[y] * (n - siz[y]),ss -= siz[y];
		}
		else low[x] = min(low[x],dfn[y]);
	}
	if (x == 1 && child < 2) flag = false;
	if (!flag) ans[x] = 2 * (n - 1);
	else ans[x] += n - 1 + 1ll * ss * (n - ss);
}

int main() {
	cin >> n >> m;
	for (int i = 1;i <= m;i++) {
		int a,b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	tarjan(1);
	for (int i = 1;i <= n;i++) cout << ans[i] << endl;
	return 0;
}