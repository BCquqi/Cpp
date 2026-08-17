#include<iostream>
using namespace std;

const int N = 2e5 + 5,mod = 998244353;
int a[N],len[N];
long long s[N];

int calc(int x) {
	int ret = 0;
	while (x) {
		ret++;
		x /= 10;
	}
	return ret;
}

long long qpow(long long a,long long b,long long p)
{
	long long ans = 1;
	while (b)
	{
		if (b & 1) ans = ans * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return ans;
}

int main() {
	int n;
	long long ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = (s[i - 1] + a[i]) % mod;
		len[i] = calc(a[i]);
	}
	for (int j = 2;j <= n;j++)
		ans += (s[j - 1] * qpow(10,len[j],mod) % mod + 1ll * a[j] * (j - 1) % mod) % mod;
	cout << ans % mod << endl;
	return 0;
}