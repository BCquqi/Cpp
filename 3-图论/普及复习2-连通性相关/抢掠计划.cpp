#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int N = 5e5 + 5;
vector<int> G[N],G2[N];
int a[N],dfn[N],low[N],st[N],id[N],in[N],out[N],money[N],dis[N],siz[N],inx = 0,cnt_scc = 0,top = 0;
bool vis[N],flag[N];

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
			money[cnt_scc] += a[y];
		} while (x != y);
	}
}

void spfa(int s) {
	queue<int> q;
	memset(vis,false,sizeof vis);
	dis[s] = money[s];
	q.push(s);
	vis[s] = true;
	while (q.size()) {
		int x = q.front();q.pop();
		vis[x] = false;
		for (auto y : G2[x]) {
			if (dis[y] >= dis[x] + money[y]) continue;
			dis[y] = dis[x] + money[y];
			if (!vis[y]) {
				q.push(y);
				vis[y] = true;
			}
		}
	}
}

int main() {
	int n,m,s,p;
	cin >> n >> m;
	for (int i = 1;i <= m;i++) {
		int x,y;
		cin >> x >> y;
		G[x].push_back(y);
	}
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++)
		if (!dfn[i]) tarjan(i);
	for (int i = 1;i <= n;i++)
		for (auto j : G[i]) {
			int x = id[i],y = id[j];
			if (x != y) G2[x].push_back(y);
		}
	cin >> s >> p;
	for (int i = 1;i <= p;i++) {
		int x;
		cin >> x;
		flag[id[x]] = true;
	}
	spfa(id[s]);
	int ans = 0;
	for (int i = 1;i <= cnt_scc;i++)
		if (flag[i]) ans = max(ans,dis[i]);
	cout << ans << endl;
	return 0;
}