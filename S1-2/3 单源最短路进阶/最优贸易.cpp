#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

const int N = 1e5 + 5;
int a[N],dis[N],vis[N],rdis[N],rvis[N],n,m,ans = 0;
vector<int> G[N],rG[N];

void spfa() {
	memset(dis,0x3f,sizeof dis);
	queue<int> q;
	q.push(1);
	dis[1] = a[1],vis[1] = true;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		vis[u] = false;
		for (auto v : G[u]) {
			if (dis[v] <= min(dis[u],a[v])) continue;
			dis[v] = min(dis[u],a[v]);
			if (!vis[v]) {
				q.push(v);
				vis[v] = true;
			}
		}
	}
}

void Rspfa() {
	memset(rdis,-0x3f,sizeof rdis);
	queue<int> q;
	q.push(n);
	rdis[n] = a[n],rvis[n] = true;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		rvis[u] = false;
		for (auto v : rG[u]) {
			if (rdis[v] >= max(rdis[u],a[v])) continue;
			rdis[v] = max(rdis[u],a[v]);
			if (!rvis[v]) {
				q.push(v);
				rvis[v] = true;
			}
		}
	}
}

int main(){
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= m;i++) {
		int x,y,z;
		cin >> x >> y >> z;
		G[x].push_back(y); rG[y].push_back(x);
		if (z == 2) {G[y].push_back(x); rG[x].push_back(y);}
	}
	spfa(); Rspfa();
	for (int i = 1;i <= n;i++) ans = max(ans,rdis[i] - dis[i]);
	cout << ans << endl;
	return 0;
}