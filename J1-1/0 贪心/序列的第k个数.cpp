#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;

int mod = 200907;

LL qpow(LL a,LL b,LL p)
{
	LL ans = 1;
	while (b)
	{
		if (b & 1) ans = ans * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return ans;
}

void solve()
{
	LL a,b,c,k;
	cin >> a >> b >> c >> k;
	if (2 * b == a + c) cout << (a + (k - 1) * (b - a)) % mod << endl;
	if (b * b == a * c) cout << a * qpow(b / a,k - 1,mod) % mod << endl;
}

int main(){
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}