#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int a[1005],b[1005],tmp[1005];

void s2BIG (string s,int a[])
{
	int al = s.length();
	for (int i = 1;i <= al;i++) a[i] = s[al - i] - '0';
	a[0] = al;
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

void printBIG(int a[])
{
	int al = a[0];
	for (int i = al;i >= 1;i--) cout << a[i];
}

bool cmpBIG(int a[],int b[])
{
	int al = a[0],bl = b[0];
	if (al != bl) return al < bl;
	for (int i = al;i >= 1;i--) if (a[i] != b[i]) return a[i] < b[i];
	return false;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		char c;
		string s;
		cin >> c >> s;
		memset(tmp,0,sizeof tmp);
		s2BIG(s,tmp);
		if (c == 'A') addBIG(a,tmp,a);
		else addBIG(b,tmp,b);
	}
	if (cmpBIG(a,b))
	{
		cout << 'B' << endl;
		printBIG(b);
	}
	else 
	{
		cout << 'A' << endl;
		printBIG(a);
	}
	return 0;
}
