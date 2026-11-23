#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int c[20 * 100005],s[20 * 100005],dp[2][100005];

void solve()
{
	memset(dp,0,sizeof dp);
	int cash,n;
	cin >> cash >> n;
	int cur = 0;
	for (int i = 1;i <= n;i++)
	{
		int x,z;
		cin >> x >> z;
		c[i] = x;
		int tmp = 1;
		while (x >= tmp)
		{
			s[++cur] = tmp * z;
			x -= tmp;
			tmp *= 2;
		}
		if (x >= 0)
		{
			s[++cur] = x * z;
		}
	}
	for (int i = 1;i <= cur;i++)
		for (int j = 0;j <= cash;j++)
		{
			dp[i & 1][j] = dp[i - 1 & 1][j];
			if (j >= s[i]) dp[i & 1][j] = max(dp[i & 1][j],dp[i - 1 & 1][j - s[i]] + s[i]);
		}
	cout << dp[cur & 1][cash] << endl;
	return ;
}

int main()
{
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}
