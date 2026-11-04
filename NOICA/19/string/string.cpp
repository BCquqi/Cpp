#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

void solve() {
	int l,r,n,m;
	cin >> l >> r >> n >> m;
	if (n < m) swap(n,m);
	int x = min(m,l);
	if (l == 1) x = 0;
	int tmp = (n + m - 1 - max(0ll,2 * x - 2)) / (2 * l) * 2 + 1;
	if (!((n + m) & 1)) tmp++;
	if (tmp <= n - m || 
		(l != 1 && n / (r + 1) >= (m + l - 2) / (l - 1) - 1) || 
		(l != 1 && m / (r + 1) >= (n + l - 2) / (l - 1) - 1)) cout << "Yes" << endl;
	else cout << "No" << endl;
	return ;
}

signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}
