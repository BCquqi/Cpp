#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

int a[105],c[105],v[2005];
bool dp[2][100005];

void solve()
{
	memset(dp,0,sizeof dp);
	dp[0][0] = 1;
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++) cin >> c[i];
	int cur = 0;
	for (int i = 1;i <= n;i++)
	{
		int x = a[i],z = c[i];
		int tmp = 1;
		while (z >= tmp)
		{
			v[++cur] = x * tmp;
			z -= tmp;
			tmp *= 2;
		}
		if (z > 0)
		{
			v[++cur] = x * z;
		}
	}
	for (int i = 1;i <= cur;i++)
		for (int j = 0;j <= m;j++)
		{
			dp[i & 1][j] = dp[i - 1 & 1][j];
			if (j >= v[i]) dp[i & 1][j] |= dp[i - 1 & 1][j - v[i]];
		}
	int ans = 0;
	for (int j = 1;j <= m;j++)
		if (dp[cur & 1][j]) ans++;
	cout << ans << endl;
}

int main()
{
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}
