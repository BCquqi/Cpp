#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int a[105],ans[105];

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

bool cmpBIG(int a[],int b[])
{
	int al = a[0],bl = b[0];
	if (al != bl) return al < bl;
	for (int i = al;i >= 1;i--) if (a[i] != b[i]) return a[i] < b[i];
	return false;
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
	int n,id = 0;
	cin >> n;
	memset(ans,0,sizeof ans);
	for (int i = 1;i <= n;i++)
	{
		string s;
		cin >> s;
		s2BIG(s,a);
		if (cmpBIG(ans,a))
		{
			mulBIG(a,1,ans);
			id = i;
		}
	}
	cout << id << endl;
	printBIG(ans);
	return 0;
}
