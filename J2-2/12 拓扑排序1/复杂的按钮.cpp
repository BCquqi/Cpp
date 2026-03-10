#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 30005;
vector<int> G[N];
priority_queue<int,vector<int>,greater<int> > q;
int topo[N],in[N],cur = 0,n,m,b;

void topo_sort() {
	for (int i = 1;i <= n;i++)
		if (in[i] == 0) q.push(i);
	while (!q.empty()) {
		int u = q.top(); q.pop();
		topo[++cur] = u;
		for (auto v : G[u])
			if (--in[v] == 0) q.push(v);
	}
}

int main() {
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> m;
		for (int j = 1;j <= m;j++) {
			cin >> b;
			G[i].push_back(b);
			in[b]++;
		}
	}
	topo_sort();
	if (cur != n) cout << "no solution" << endl;
	else {
		cout << n << endl;
		for (int i = 1;i <= n;i++) cout << topo[i] << ' ';
		cout << endl;
	}
	return 0;
}