#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
vector<int> G[N],a[N];
int in[N],topo[N],cur = 0,n,m;

bool topo_sort1() {
	cur = 0;
	queue<int> q;
	for (int i = 1;i <= n;i++)
		if (in[i] == 0) q.push(i);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		topo[++cur] = u;
		for (auto v : G[u])
			if (--in[v] == 0) q.push(v);
	}
	return cur == n;
}

bool topo_sort2() {
	cur = 0;
	priority_queue<int,vector<int>,greater<int> > q;
	for (int i = 1;i <= n;i++)
		if (in[i] == 0) q.push(i);
	while (!q.empty()) {
		int u = q.top(); q.pop();
		topo[++cur] = u;
		for (auto v : G[u])
			if (--in[v] == 0) q.push(v);
	}
	return cur == n;
}

bool check1(int mid) {
	for (int i = 1;i <= n;i++) {
		G[i].clear();
		in[i] = 0;
	}
	for (int i = 1;i <= mid;i++) {
		int len = a[i].size();
		for (int j = 0;j < len - 1;j++) {
			G[a[i][j]].push_back(a[i][j + 1]);
			in[a[i][j + 1]]++;
		}
	}
	return topo_sort1();
}

bool check2(int mid) {
	for (int i = 1;i <= n;i++) {
		G[i].clear();
		in[i] = 0;
	}
	for (int i = 1;i <= mid;i++) {
		int len = a[i].size();
		for (int j = 0;j < len - 1;j++) {
			G[a[i][j]].push_back(a[i][j + 1]);
			in[a[i][j + 1]]++;
		}
	}
	return topo_sort2();
}

int main() {
	cin >> n >> m;
	for (int i = 1;i <= m;i++) {
		int mi;
		cin >> mi;
		for (int j = 1;j <= mi;j++) {
			int tmp;
			cin >> tmp;
			a[i].push_back(tmp);
		}
	}
	int l = 0,r = m + 1,ans = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check1(mid)) l = mid + 1,ans = mid;
		else r = mid - 1;
	}
	check2(ans);
	for (int i = 1;i <= cur;i++) cout << topo[i] << ' ';
	cout << endl;
	return 0;
}