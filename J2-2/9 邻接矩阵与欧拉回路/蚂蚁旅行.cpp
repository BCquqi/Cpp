#include<iostream>
using namespace std;

const int N = 1e3 + 5;
int deg[N];

int main() {
	int n,m,cnt = 0;
	cin >> n >> m;
	for (int i = 1;i <= m;i++) {
		int a,b;
		cin >> a >> b;
		deg[a]++,deg[b]++;
	}
	for (int i = 1;i <= n;i++)
		if (deg[i] % 2 == 1) cnt++;
	cout << ((cnt == 0) ? 1 : cnt / 2) << endl;
	return 0;
}