#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

int ans[5000005];

void s2BIG(string s,int a[])
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

void mulBIG(int a[],int b,int c[])
{
	int cl = min(a[0],500);
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
	int p;
	cin >> p;
	cout << int(p * log10(2)) + 1 << endl;
	ans[0] = ans[1] = 1;
	for (int i = 1;i <= p / 20;i++) mulBIG(ans,1024 * 1024,ans);
	for (int i = 1;i <= p % 20;i++) mulBIG(ans,2,ans);
	ans[1] -= 1;
	for (int i = 500;i >= 1;i--)
	{
		cout << ans[i];
		if (i % 50 == 1) cout << endl;
	}
	return 0;
}
