#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int mul[1000005];

void s2BIG (string s,int a[])
{
	int al = s.length();
	for (int i = 1;i <= al;i++) a[i] = s[al - i] - '0';
	a[0] = al;
}

void mulBIG(int a[],int b,int c[])
{
	int cl = a[0];
	long long u = 0;
	for (int i = 1;i <= cl;i++)
	{
		int t = 1ll * a[i] * b + u;
		c[i] = t % 10;
		u = t / 10;
	}
	while (u > 0)
	{
		cl++;
		c[cl] = u % 10;
		u /= 10;
	}
	c[0] = cl;
}

int main()
{
	int n,a;
	cin >> n >> a;
	s2BIG("1",mul);
	for (int i = 1;i <= n;i++) mulBIG(mul,i,mul);
	int ans = 0;
	for (int i = 1;i <= mul[0];i++)
		if (mul[i] == a) ans++;
	cout << ans << endl;
	return 0;
}
