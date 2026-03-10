#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int N = 1005;
int tmp[N],cnt[N],a,b,n; bool vis[N];
long long dis[N];
struct Edge {
	int v,w,d;
}; vector<Edge> G[N];

void spfa() {
	memset(dis,0x3f,sizeof dis);
	memset(cnt,0x3f,sizeof cnt);
	queue<int> q;
	q.push(a);
	dis[a] = 0,vis[a] = 1,cnt[a] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		vis[u] = 0;
		for (auto p : G[u]) {
			int v = p.v,w = p.w,d = p.d;
			if (dis[v] < dis[u] + w) continue;
			if (dis[v] == dis[u] + w && cnt[v] <= cnt[u] + d) continue;
			dis[v] = dis[u] + w,cnt[v] = cnt[u] + d;
			if (vis[v] == 0) q.push(v);
			vis[v] = 1;
		}
	}
}

int main() {
	cin >> a >> b >> n;
	for (int i = 1;i <= n;i++) {
		int cost,num;
		cin >> cost >> num;
		for (int j = 1;j <= num;j++) cin >> tmp[j];
		for (int j = 1;j <= num;j++)
			for (int k = j + 1;k <= num;k++)
				G[tmp[j]].push_back({tmp[k],cost,k - j});
	}
	spfa();
	cout << (dis[b] == 0x3f3f3f3f3f3f3f3f ? -1 : dis[b]) << ' ' << (cnt[b] == 0x3f3f3f3f ? -1 : cnt[b]) << endl;
	return 0;
}