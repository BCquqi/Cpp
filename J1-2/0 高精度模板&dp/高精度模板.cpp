// J1-2 高精度集合
#include<iostream>
#include<cstring>
using namespace std;

void s2BIG (string s,int a[]) // s to BIG
{
	int al = s.length();
	for (int i = 1;i <= al;i++) a[i] = s[al - i] - '0';
	a[0] = al;
}

void printBIG(int a[]) // printf BiG
{
	int al = a[0];
	for (int i = al;i >= 1;i--) cout << a[i];
}

bool cmpBIG(int a[],int b[]) // compare BIG(a,b)
{
	int al = a[0],bl = b[0];
	if (al != bl) return al < bl;
	for (int i = al;i >= 1;i--) if (a[i] != b[i]) return a[i] < b[i];
	return false;
}

void addBIG(int a[],int b[],int c[]) // add BIG(a,b) to c
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

void subBIG(int a[],int b[],int c[]) // sub BIG(a,b) to c
{
	int al = a[0],bl = b[0];
	int cl = al;
	int u = 0;
	for (int i = 1;i <= cl;i++)
	{
		int t = a[i] - u;
		if (i <= bl) t -= b[i];
		if (t < 0)
		{
			c[i] = t + 10;
			u = 1;
		}
		else 
		{
			c[i] = t;
			u = 0;
		}
	}
	while (c[cl] == 0 && cl > 1) cl--;
	c[0] = cl;
}

void mulBIG(int a[],int b,int c[]) // mul BIG a with b to c
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

void divBIG(int a[],int b,int c[]) // div BIG a with b to c
{
	int cl = a[0];
	long long r = 0;
	for (int i = cl;i >= 1;i--)
	{
		r = r * 10 + a[i];
		c[i] = r / b;
		r %= b;
	}
	while (c[cl] == 0 && cl > 1) cl--;
	c[0] = cl;
}