#include<iostream>
#include<vector>
using namespace std;

const int N = 1e4 + 5;
vector<int> G[N];
int dfn[N],low[N],st[N],siz[N],id[N],in[N],top = 0,inx = 0,cnt_scc = 0;
bool vis[N];

void tarjan(int x) {
	dfn[x] = low[x] = ++inx;
	st[++top] = x,vis[x] = true;
	for (auto y : G[x]) {
		if (!dfn[y]) {
			tarjan(y);
			low[x] = min(low[x],low[y]);
		}
		else if (vis[y]) low[x] = min(low[x],dfn[y]);
	}
	if (dfn[x] == low[x]) {
		cnt_scc++;
		int y;
		do {
			y = st[top--];
			vis[y] = false;
			id[y] = cnt_scc;
			siz[cnt_scc]++;
		} while (x != y);
	}
}

int main() {
	int n,m,ans = 0;
	cin >> n >> m;
	for (int i = 1;i <= m;i++) {
		int a,b;
		cin >> a >> b;
		G[a].push_back(b);
	}
	for (int i = 1;i <= n;i++)
		if (!dfn[i]) tarjan(i);
	for (int i = 1;i <= cnt_scc;i++)
		if (siz[i] > 1) ans++;
	cout << ans << endl;
	return 0;
}