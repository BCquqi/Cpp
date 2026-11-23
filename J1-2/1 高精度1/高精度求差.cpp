#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

int a[1005],b[1005],c[1005],tmp[1005],zero[1005];

void s2BIG (string s,int a[])
{
	int al = s.length();
	for (int i = 1;i <= al;i++) a[i] = s[al - i] - '0';
	a[0] = al;
}

bool cmpBIG(int a[],int b[])
{
	int al = a[0],bl = b[0];
	if (al != bl) return al < bl;
	for (int i = al;i >= 1;i--) if (a[i] != b[i]) return a[i] < b[i];
	return false;
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

void printBIG(int a[])
{
	int al = a[0];
	for (int i = al;i >= 1;i--) cout << a[i];
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
	string s;
	cin >> s;
	s2BIG(s,a); s2BIG(s,b);
	for (int i = 2;i <= n;i++)
	{
		cin >> s;
		memset(tmp,0,sizeof tmp);
		s2BIG(s,tmp);
		if (cmpBIG(a,tmp)) addBIG(tmp,zero,a);
		if (cmpBIG(tmp,b)) addBIG(tmp,zero,b);
	}
	subBIG(a,b,c);
	printBIG(c);
	return 0;
}
