#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int M[1005],F[5005][1005];

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

int main(){
	string m;
	cin >> m;
	s2BIG(m,M); s2BIG("1",F[1]); s2BIG("1",F[2]);
	for (int i = 3;true;i++)
	{
		addBIG(F[i - 1],F[i - 2],F[i]);
		if (check(F[i],M))
		{
			printBIG(F[i]);
			break;
		}
	}
	return 0;
}
