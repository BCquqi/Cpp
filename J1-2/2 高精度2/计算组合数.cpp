// Solution 1
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

int ans[10005];

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

int main() {
	int n,m;
	cin >> n >> m;
	s2BIG("1",ans);
	for (int i = 1;i <= n;i++) mulBIG(ans,i,ans);
	for (int i = 1;i <= m;i++) divBIG(ans,i,ans);
	for (int i = 1;i <= n - m;i++) divBIG(ans,i,ans);
	printBIG(ans);
	return 0;
}
