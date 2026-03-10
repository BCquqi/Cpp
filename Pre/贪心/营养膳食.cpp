#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct Node {
	int a,b;
} s[205];

int cnt[105];

bool cmp(Node x,Node y)
{
	return x.a > y.a;
}

int main() {
	int n,m,k;
	cin >> n >> m >> k;
	for (int i = 1;i <= k;i++)
	{
		cin >> cnt[i];
	}
	for (int i = 1;i <= n;i++)
	{
		cin >> s[i].a >> s[i].b;
	}
	sort(s + 1,s + n + 1,cmp);
	int ans = 0;
	for (int i = 1;i <= n;i++)
	{
		if (cnt[s[i].b] > 0 && m > 0)
		{
			m--;
			cnt[s[i].b]--;
			ans += s[i].a;
		}
	}
	cout << ans << endl;
    return 0;
}
