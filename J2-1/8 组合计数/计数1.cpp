#include<iostream>
using namespace std;
typedef long long LL;

const int mod = 1e9 + 7;

LL qpow(LL a,LL b,LL p)
{
	LL ans = 1;
	while (b)
	{
		if (b & 1) ans = ans * a % p;;
		a = a * a % p;
		b >>= 1;
	}
	return ans;
}

int main()
{
	int n;
	cin >> n;
	cout << 1ll * ((qpow(3,n,mod) - (1ll * qpow(2,n,mod) * 3 % mod) + mod) % mod + 3) % mod << endl;
	return 0;
}