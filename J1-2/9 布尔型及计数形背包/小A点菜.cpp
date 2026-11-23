#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

int a[105],dp[105][10005];

int main()
{
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	dp[0][0] = 1;
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= m;j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= a[i]) dp[i][j] += dp[i - 1][j - a[i]];
		}
	cout << dp[n][m] << endl;
	return 0;
}
