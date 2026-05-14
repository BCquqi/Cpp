#include<iostream>
#include<vector>
using namespace std;

const int N = 2e5 + 5;
int t[N],dfn[N],low[N],st[N],vis[N],siz[N],id[N],cnt_scc = 0,inx = 0,top = 0;
vector<int> G[N];

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
	int n,ans = 1e9;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> t[i];
		G[i].push_back(t[i]);
	}
	for (int i = 1;i <= n;i++)
		if (!dfn[i]) tarjan(i);
	for (int i = 1;i <= cnt_scc;i++) 
		if (siz[i] > 1) ans = min(ans,siz[i]);
	cout << ans << endl;
	return 0;
}