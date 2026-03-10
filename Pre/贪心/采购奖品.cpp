#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

struct Node {
	int p,a;
} s[105];

bool cmp(Node x,Node y)
{
	return x.p < y.p;
}

int main(){
	int m,n;
	cin >> m >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> s[i].p >> s[i].a;
	}
	sort(s + 1,s + n + 1,cmp);
	int ans = 0;
	for (int i = 1;i <= m;i++)
	{
		if (m - s[i].a * s[i].p >= 0)
		{
			m -= s[i].a * s[i].p;
			ans += s[i].a;
		}
		else
		{
			ans += m / s[i].p;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
