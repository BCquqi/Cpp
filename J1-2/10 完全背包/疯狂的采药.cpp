#include<iostream>
using namespace std;

int a[10005],b[10005],dp[2][10000005];

int main()
{
	int t,m;
	cin >> t >> m;
	for (int i = 1;i <= m;i++) cin >> a[i] >> b[i];
	dp[0][0] = 0;
	for (int i = 1;i <= m;i++)
		for (int j = 0;j <= t;j++)
		{
			dp[i & 1][j] = dp[i - 1 & 1][j];
			if (j >= a[i]) dp[i & 1][j] = max(dp[i & 1][j],dp[i & 1][j - a[i]] + b[i]);
		}
	cout << dp[m & 1][t] << endl;
	return 0;
}
