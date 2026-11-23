// 高精乘单精
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int a[1005],b,c[10005];

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

int main(){
	string s;
	cin >> s >> b;
	s2BIG(s,a);
	mulBIG(a,b,c);
	printBIG(c);
	return 0;
}
