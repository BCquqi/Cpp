#include<iostream>
#define int long long
using namespace std;

const int N = 1e3 + 5,mod = 998244353;
int l[N],r[N],b[N],s[N],sq[N]; // s 维护前缀和，sq 维护前缀平方和 (以段为单位)

signed main() {
	int n,m,q;
	cin >> n >> m >> q;
	for (int i = 1;i <= m;i++) {
		cin >> l[i] >> r[i] >> b[i];
		b[i] %= mod;
		s[i] = (r[i] - l[i] + 1) % mod * b[i] % mod;
		sq[i] = (r[i] - l[i] + 1) % mod * b[i] % mod * b[i] % mod;
	}
	for (int i = 1;i <= m;i++)
		s[i] = (s[i] + s[i - 1]) % mod,sq[i] = (sq[i] + sq[i - 1]) % mod;
	while (q--) {
		int x,y;
		cin >> x >> y;
		int posx = lower_bound(r + 1,r + m + 1,x) - r,posy = lower_bound(r + 1,r + m + 1,y) - r;
		int sum = 0,sqsum = 0;
		if (posx == posy) {
			sum = (y - x + 1) % mod * b[posx] % mod;
			sqsum = (y - x + 1) % mod * b[posx] % mod * b[posx] % mod;
		} else {
			sum = (sum + (r[posx] - x + 1) % mod * b[posx] % mod) % mod;
			sum = (sum + (y - l[posy] + 1) % mod * b[posy] % mod) % mod;
			sqsum = (sqsum + (r[posx] - x + 1) % mod * b[posx] % mod * b[posx] % mod) % mod;
			sqsum = (sqsum + (y - l[posy] + 1) % mod * b[posy] % mod * b[posy] % mod) % mod;
			if (posy - posx >= 2)
				sum = (sum + (s[posy - 1] - s[posx] + mod) % mod) % mod,
				sqsum = (sqsum + (sq[posy - 1] - sq[posx] + mod) % mod) % mod;
		}
		cout << ((y - x + 1) % mod * sqsum % mod - sum * sum % mod) % mod << endl;
	}
	return 0;
}
