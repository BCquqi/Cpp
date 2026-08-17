#include<iostream>
using namespace std;

void solve() {
	int n,m,q;
	cin >> n >> m >> q;
	for (int i = 1;i <= m;i++) {
		int x,y;
		cin >> x >> y;
		G[x].push_back(y); G[y].push_back(x);
	}
	return ;
}

int main() {
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}
