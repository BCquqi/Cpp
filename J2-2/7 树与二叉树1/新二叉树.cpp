#include<iostream>
using namespace std;

const int N = 130;
char l[N],r[N],p[N],node[N];

void first_search(char u) {
	cout << u;
	if (l[u] != '*') first_search(l[u]);
	if (r[u] != '*') first_search(r[u]);
	return ;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		char lc,rc;
		cin >> node[i] >> lc >> rc;
		l[node[i]] = lc;
		r[node[i]] = rc;
		p[lc] = p[rc] = node[i];
	}
	char rt;
	for (char i = 1;i <= n;i++) if (!p[node[i]]) rt = node[i];
	first_search(rt);
	cout << endl;
	return 0;
}