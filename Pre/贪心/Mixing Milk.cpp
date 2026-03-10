#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

struct Node {
	int p,a;
} s[5005];

bool cmp(Node x,Node y)
{
	return x.p < y.p;
}

int main(){
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= m;i++)
	{
		cin >> s[i].p >> s[i].a;
	}
	sort(s + 1,s + m + 1,cmp);
	int ans = 0;
	for (int i = 1;i <= m;i++)
	{
		if (n >= s[i].a)
		{
			n -= s[i].a;
			ans += s[i].a * s[i].p;
		}
		else
		{
			ans += s[i].p * n;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
