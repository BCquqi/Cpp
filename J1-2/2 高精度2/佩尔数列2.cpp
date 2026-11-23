#include<iostream>
#include<cstring>
using namespace std;

int x[2005][10005],tmp[10005];

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

void subBIG(int a[],int b[],int c[])
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
	int n;
	cin >> n;
	s2BIG("1",x[1]); s2BIG("1",x[2]);
	for (int i = 3;i <= n;i++)
	{
		mulBIG(x[i - 1],4,tmp);
		subBIG(tmp,x[i - 2],x[i]);
	}
	printBIG(x[n]);
	return 0;
}
