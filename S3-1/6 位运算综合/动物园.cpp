#include<cstdio>
#include<iostream>
#include<algorithm>
#define int unsigned long long
using namespace std;

const int N = 1e6 + 5;
int p[N],q[N];
bool flag[N];

signed main() {
	int n,m,c,k;
	unsigned long long a = 0;
	cin >> n >> m >> c >> k;
	for (int i = 1;i <= n;i++) {
		unsigned long long x;
		cin >> x;
		a |= x;
	}
	for (int i = 1;i <= m;i++) cin >> p[i] >> q[i];
	for (int i = 1;i <= m;i++) {
		if (!((a >> p[i]) & 1)) {
			if (flag[p[i]]) continue;
			k--,flag[p[i]] = true;
		}
	}
	if (k == 64 && n == 0) cout << "18446744073709551616" << endl;
	else cout << (1ull << k) - n << endl;
	return 0;
}