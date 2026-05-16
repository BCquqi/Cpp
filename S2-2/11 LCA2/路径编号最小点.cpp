#include<iostream>
#include<vector>
using namespace std;

const int N = 5e5 + 5;
vector<int> G[N];
int fa[N][32],minn[N][32],dep[N];

void dfs(int u,int pa) {
	dep[u] = dep[pa] + 1;
    fa[u][0] = pa;
    minn[u][0] = (pa == 0) ? u : min(u,pa);
    for (int i = 1;i <= 30;i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1],
        minn[u][i] = min(minn[fa[u][i - 1]][i - 1],minn[u][i - 1]);
    for (auto v : G[u]) {
    	if (v == pa) continue;
        dfs(v,u);
    }
}

int LCA(int u,int v) {
	if (dep[u] < dep[v]) swap(u,v);
    for (int i = 30;i >= 0;i--)
        if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
    if (u == v) return v;
    for (int i = 30;i >= 0;i--)
        if (fa[u][i] != fa[v][i])
            u = fa[u][i],v = fa[v][i];
    return fa[u][0];
}

int query(int a,int b) {
	int ans = min(a,b);
	if (dep[a] < dep[b]) swap(a,b);
	for (int i = 30;i >= 0;i--)
		if (dep[fa[a][i]] >= dep[b]) ans = min(ans,minn[a][i]),a = fa[a][i];
	if (a == b) return ans;
	for (int i = 30;i >= 0;i--)
		if (fa[a][i] != fa[b][i])
			ans = min(ans,minn[a][i]),
			ans = min(ans,minn[b][i]),
			a = fa[a][i],
			b = fa[b][i];
	return min(ans,min(minn[b][0],minn[a][0]));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,m,s;
	cin >> n >> m >> s;
	for (int i = 1;i < n;i++) {
		int x,y;
		cin >> x >> y;
		G[x].push_back(y); G[y].push_back(x);
	}
	dep[s] = 1;
	dfs(s,0);
	while (m--) {
		int a,b;
		cin >> a >> b;
		cout << query(a,b) << endl;
	}
	return 0;
}