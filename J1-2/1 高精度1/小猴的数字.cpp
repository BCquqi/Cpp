#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

int a[3005],b[3005],c[30005];

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
	int L1,R1,L2,R2;
	cin >> L1 >> R1 >> L2 >> R2;
	string s1,s2;
	for (int i = L1;i <= R1;i++) s1 += to_string(i);
	for (int i = L2;i <= R2;i++) s2 += to_string(i);
	s2BIG(s1,a); s2BIG(s2,b);
	addBIG(a,b,c);
	printBIG(c);
	return 0;
}
