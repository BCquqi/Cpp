#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long LL;

int p,n,x[10005];
int cur = 0;

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

bool check(int a)
{
	for (int i = 1;i <= cur;i++)
		if (qpow(a,x[i],p) == 1) return false;
	return true;
}

int main()
{
	cin >> p >> n;
	int t = p - 1;
	x[++cur] = 1;
	for (int i = 2;i * i <= t;i++)
		if (t % i == 0) x[++cur] = i,x[++cur] = t / i;
	for (int i = 2;i <= p - 1;i++)
		if (check(i))
		{
			cout << i << endl;
			if (--n == 0) break;
		}
}