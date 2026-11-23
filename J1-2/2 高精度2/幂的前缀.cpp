#include<iostream>
#include<cstring>
using namespace std;

int a[5005],c[5005],M[5005];

bool check(int a[],int b[])
{
	if (a[0] < b[0]) return false;
	for (int i = 1;i <= b[0];i++) if (a[a[0] - i + 1] != b[b[0] - i + 1]) return false;
	return true;
}

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

int main()
{
	string m;
	cin >> m;
	s2BIG(m,M);
	s2BIG("1",a);
	for (int i = 1;true;i++)
	{
		mulBIG(a,2,a);
		if (check(a,M))
		{
			printBIG(a);
			break;
		}
	}
	return 0;
}
