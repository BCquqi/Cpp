#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int p[1005],v[1005],dp[1005][1005];

int main()
{
	int c,n;
	cin >> c >> n;
	for (int i = 1;i <= n;i++) cin >> p[i] >> v[i];
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= c;j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= p[i]) dp[i][j] = max(dp[i][j],dp[i - 1][j - p[i]] + v[i]);
		}
	cout << dp[n][c] << endl;
	return 0;
}
