#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1005;
int a[N],b[N],in[N],out[N],topo[N],dp[N],tmp[N],cur = 0,n,m,ans = 0;
bool vis[N],G[N][N];
queue<int> q;

void topo_sort() {
	cur = 0;
    for (int i = 1;i <= n;i++)
		if (tmp[i] == 0) q.push(i);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		topo[++cur] = u;
		for (int v = 1;v <= n;v++)
			if (G[u][v] && --tmp[v] == 0) q.push(v);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1;i <= m;i++) {
		int s,cur = 0;
		cin >> s;
		memset(vis,false,sizeof vis);
		for (int i = 1;i <= s;i++) {
			cin >> a[i];
			vis[a[i]] = true;
		}
		for (int i = a[1];i <= a[s];i++)
			if (vis[i] == false) b[++cur] = i;
		for (int i = 1;i <= s;i++)
			for (int j = 1;j <= cur;j++) G[a[i]][b[j]] = 1;
	}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			if (G[i][j]) in[j]++,tmp[j]++,out[i]++;
	topo_sort();
	memset(dp,-0x3f,sizeof dp);
	for (int i = 1;i <= n;i++)
		if (in[i] == 0) dp[i] = 1;
	for (int i = 1;i <= n;i++) {
		int u = topo[i];
		for (int v = 1;v <= n;v++)
			if (G[u][v]) dp[v] = max(dp[v],dp[u] + 1);
		if (out[u] == 0) ans = max(ans,dp[u]);
	}
	cout << ans << endl;
	return 0;
}