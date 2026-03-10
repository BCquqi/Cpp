#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

struct Node {
	int h,a;
} s[40005];

bool cmp(Node x,Node y)
{
	return x.a < y.a;
}

int dp[2][40005];

int main()
{
	int n,cur = 0;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		int x,y,z;
		cin >> x >> y >> z;
		int tmp = 1;
		while (z >= tmp)
		{
			s[++cur].a = y;
			s[cur].h = x * tmp;
			z -= tmp;
			tmp *= 2;
		}
		if (z > 0)
		{
			s[++cur].a = y;
			s[cur].h = x * z;
		}
	}
	sort(s + 1,s + cur + 1,cmp);
	for (int i = 1;i <= cur;i++)
		for (int j = 0;j <= 40000;j++)
		{
			dp[i & 1][j] = dp[i - 1 & 1][j];
			if (j >= s[i].h && j <= s[i].a)
				dp[i & 1][j] = max(dp[i & 1][j],dp[i - 1 & 1][j - s[i].h] + s[i].h);
		}
	int ans = -1e9;
	for (int j = 0;j <= 40000;j++) ans = max(ans,dp[cur & 1][j]);
	cout << ans << endl;
	return 0;
}
