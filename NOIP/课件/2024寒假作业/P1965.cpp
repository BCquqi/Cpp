#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;

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
	int n,m,k,x;
	cin >> n >> m >> k >> x;
	cout << (x + m * qpow(10,k,n)) % n << endl;
	return 0;
}
