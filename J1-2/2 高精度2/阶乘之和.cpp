#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

int a,b[1005],c[10005];

void s2BIG (string s,int a[])
{
	int al = s.length();
	for (int i = 1;i <= al;i++) a[i] = s[al - i] - '0';
	a[0] = al;
}

void printBIG(int a[])
{
	int al = a[0];
	for (int i = al;i >= 1;i--) cout << a[i];
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

void addBIG(int a[],int b[],int c[])
{
	int al = a[0],bl = b[0];
	int cl = max(al,bl);
	int u = 0;
	for (int i = 1;i <= cl;i++)
	{
		int t = u;
		if (i <= al) t += a[i];
		if (i <= bl) t += b[i];
		c[i] = t % 10;
		u = t / 10;
	}
	if (u > 0)
	{
		cl++;
		c[cl] = u;
	}
	c[0] = cl;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		memset(b,0,sizeof b);
		cin >> a;
		s2BIG("1",b);
		for (int i = 1;i <= a;i++) mulBIG(b,i,b);
		addBIG(b,c,c);
	}
	printBIG(c);
	return 0;
}
