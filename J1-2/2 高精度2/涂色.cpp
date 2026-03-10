#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int ans[10005],mul;

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

int main(){
	int n,intk;
	cin >> n >> intk;
	string k = to_string(intk);
	s2BIG(k,ans);
	mul = intk - 1;
	for (int i = 2;i <= n;i++)
	{
		mulBIG(ans,mul,ans);
	}
	printBIG(ans);
	return 0;
}
