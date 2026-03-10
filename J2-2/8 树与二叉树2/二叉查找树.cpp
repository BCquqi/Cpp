#include<iostream>
using namespace std;

const int N = 1e5 + 5;
struct Node {
	int lch,rch,p;
} a[N];

void mid_search(int u) {
	if (a[u].lch) mid_search(a[u].lch);
	cout << a[u].p << ' ';
	if (a[u].rch) mid_search(a[u].rch);
	return ;
}

void last_search(int u) {
	if (a[u].lch) last_search(a[u].lch);
	if (a[u].rch) last_search(a[u].rch);
	cout << a[u].p << ' ';
	return ;
}

void insert(int id,int root) {
	if (a[id].p > a[root].p) {
		if (a[root].rch == 0) a[root].rch = id;
		else insert(id,a[root].rch);
	}
	else {
		if (a[root].lch == 0) a[root].lch = id;
		else insert(id,a[root].lch);
	}
}

int main() {
	int n;
	cin >> n >> a[1].p;
	for (int i = 2;i <= n;i++) {
		cin >> a[i].p;
		insert(i,1);
	}
	mid_search(1);
	cout << endl;
	last_search(1);
	cout << endl;
	return 0;
}