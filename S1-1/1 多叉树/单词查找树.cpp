#include<iostream>
using namespace std;

string s; int cur = 1;

struct Node {
	int child[130] = {};
} a[(1 << 15) + 5];

void dfs(int u,int step) {
	if (step >= s.size()) return ;
	if (a[u].child[s[step]] == 0) a[u].child[s[step]] = ++cur;
	dfs(a[u].child[s[step]],step + 1);
}

int main() {
	while (cin >> s) dfs(1,0);
	cout << cur << endl;
	return 0;
}