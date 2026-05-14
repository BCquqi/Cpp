#include<iostream>
using namespace std;

const int N = 1e6 + 5;
int color[N],f[N];

int find(int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}

int main() {
	int n,m,p,q;
	cin >> n >> m >> p >> q;
	for (int i = 1;i <= n + 1;i++) f[i] = i;
	for (int i = m;i >= 1;i--) {
		int l = (i * p + q) % n + 1,r = (i * q + p) % n + 1;
		if (l > r) swap(l,r);
		for (int j = find(l);j <= r;j = find(j + 1)) {
			color[j] = i;
			f[j] = j + 1;
		}
	}
	for (int i = 1;i <= n;i++) cout << color[i] << '\n';
	return 0;
}