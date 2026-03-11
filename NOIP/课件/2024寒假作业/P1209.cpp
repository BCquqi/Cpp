#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int a[205],b[205];

bool cmp(int a,int b)
{
	return a > b;
}

int main(){
	int m,s,c;
	cin >> m >> s >> c;
	for (int i = 1;i <= c;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + c + 1);
	for (int i = 1;i <= c;i++)
	{
		b[i] = a[i + 1] - a[i] - 1;
	}
	sort(b + 1,b + c + 1,cmp);
	int cnt = 1,ans = a[c] - a[1] + 1;
	for (int i = 1;i <= c - 1 && cnt < m;i++)
	{
		ans -= b[i];
		cnt++;
	}
	cout << ans << endl;
	return 0;
}
