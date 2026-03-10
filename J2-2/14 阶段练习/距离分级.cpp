#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
vector<int> G[N];
queue<int> q;
int dis[N],sl[N],tmp = 0,cur = 0; bool vis[N];

void bfs(int s) {
	memset(dis,0x3f,sizeof dis);
	memset(vis,false,sizeof vis);
	q.push(s);
	vis[s] = true, dis[s] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (tmp != dis[u]) {
			sort(sl + 1,sl + cur + 1);
			for (int i = 1;i <= cur;i++) cout << sl[i] << ' ';
			cout << endl;
			memset(sl,0,sizeof sl);
			tmp = dis[u],cur = 0;
		}
		sl[++cur] = u;
		for (auto v : G[u])
			if (!vis[v]) {
				q.push(v);
				vis[v] = true, dis[v] = dis[u] + 1;
			}
	}
}

int main() {
	int n,m,x;
	cin >> n >> m >> x;
	for (int i = 1;i <= m;i++) {
		int s,t;
		cin >> s >> t;
		G[s].push_back(t);
	}
	bfs(x);
    sort(sl + 1,sl + cur + 1);
    for (int i = 1;i <= cur;i++) cout << sl[i] << ' ';
    cout << endl;
    memset(sl,0,sizeof sl);
    for (int i = 1;i <= n;i++)
        if (!vis[i]) cout << i << ' ';
    cout << endl;
	return 0;
}