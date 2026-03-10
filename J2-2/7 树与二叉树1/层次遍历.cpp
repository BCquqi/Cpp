#include<iostream>
#include<queue>
using namespace std;

const int N = 1e4 + 5;
struct Node {
	int lch,rch,p,dep;
} a[N];

void bfs() {
	queue<int> q;
	q.push(1);
	a[1].dep = 1;
	int cnt = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (a[u].dep != cnt) {cnt++; cout << endl;}
		cout << u << ' ';
		if (a[u].lch) {q.push(a[u].lch); a[a[u].lch].dep = a[u].dep + 1;}
		if (a[u].rch) {q.push(a[u].rch); a[a[u].rch].dep = a[u].dep + 1;}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> a[i].lch >> a[i].rch;
		a[a[i].lch].p = a[a[i].rch].p = i;
	}
	bfs();
	cout << endl;
	return 0;
}