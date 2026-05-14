#include<iostream>
#include<vector>
#include<set>
using namespace std;

const int N = 105;
vector<int> G[N];
set<long long> s;
int dfn[N],low[N],st[N],siz[N],id[N],in[N],out[N],top = 0,inx = 0,cnt_scc = 0;
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
	int n,ans1 = 0,ans2 = 0;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		int m;
		while (true) {
			cin >> m;
			if (m == 0) break;
			else G[i].push_back(m);
		}
	}
	for (int i = 1;i <= n;i++)
		if (!dfn[i]) tarjan(i);
	for (int i = 1;i <= n;i++)
		for (auto j : G[i]) {
			int x = id[i],y = id[j];
			long long hash = 1ll * x * N + y;
			if (x != y && s.count(hash) == 0) {
				in[y]++,out[x]++;
				s.insert(hash);
			}
		}
	for (int i = 1;i <= cnt_scc;i++) {
		if (in[i] == 0) ans1++;
		if (out[i] == 0) ans2++;
	}
	cout << ans1 << endl;
	if (cnt_scc == 1) cout << 0 << endl;
	else cout << max(ans1,ans2) << endl;
	return 0;
}