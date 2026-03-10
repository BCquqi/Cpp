#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 100005;
int in[N],tmp[N],topo[N],dp1[N],dp2[N],cur = 0,n;
vector<int> G[N];
queue<int> q;

void topo_sort() {
    for (int i = 1;i <= n;i++)
		if (tmp[i] == 0) q.push(i);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		topo[++cur] = u;
		for (auto v : G[u])
			if (--tmp[v] == 0) q.push(v);
	}
}

int main() {
    cin >> n;
    for (int i = 1;i <= n;i++) dp1[i] = dp2[i] = 1;
    for (int i = 1;i < n;i++) {
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        in[b]++,tmp[b]++;
    }
    topo_sort();
    for (int i = 1;i <= n;i++) {
        int u = topo[i];
        for (auto v : G[u]) dp1[v] += dp1[u];
    }
    for (int i = n;i >= 1;i--) {
        int u = topo[i];
        for (auto v : G[u]) dp2[u] += dp2[v];
    }
    for (int i = 1;i <= n;i++)
        if (in[i] != 0 && dp1[i] + dp2[i] == n + 1) cout << i << endl;
    return 0;
}