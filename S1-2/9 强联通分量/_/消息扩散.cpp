#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5 + 5;
vector<int> G[N];
int idx = 0,cnt_scc = 0,top = 0,in[N],dfn[N],low[N],st[N],siz[N],id[N];
bool vis[N];

void tarjan(int x) {
    dfn[x] = low[x] = ++idx;
    st[++top] = x;
    vis[x] = true;
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
		int b,e;
		cin >> b >> e;
		G[b].push_back(e);
	}
	for (int i = 1;i <= n;i++)
		if (!dfn[i]) tarjan(i);
	for (int i = 1;i <= n;i++)
        for (auto j : G[i]) if (id[i] != id[j]) in[id[j]]++;
    for (int i = 1;i <= cnt_scc;i++)
        if (in[i] == 0) ans++;
    cout << ans << endl;
	return 0;
}