#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;

int mod = 1e5 + 3;

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

int main(){
	LL m,n;
	cin >> m >> n;
	cout << (mod + qpow(m,n,mod) - m * qpow(m - 1,n - 1,mod) % mod) % mod << endl;
	return 0;
}