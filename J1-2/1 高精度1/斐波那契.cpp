#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int F[4005][1005];

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

int main() {
	int n;
	cin >> n;
	s2BIG("1",F[1]); s2BIG("1",F[2]);
	for (int i = 3;i <= n;i++) addBIG(F[i - 1],F[i - 2],F[i]);
	printBIG(F[n]);
	return 0;
}
