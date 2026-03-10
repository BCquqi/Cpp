// 高精除(以)单精
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int a[1005],b,c[1005];

void divBIG(int a[],int b,int c[])
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
	divBIG(a,b,c);
	printBIG(c);
	return 0;
}
