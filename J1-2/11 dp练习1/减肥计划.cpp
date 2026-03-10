#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int s[105],dp[105][20005];

int main()
{
	int m,n;
	cin >> m >> n;
	for (int i = 1;i <= n;i++) cin >> s[i];
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= m;j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= s[i]) dp[i][j] = max(dp[i][j],dp[i - 1][j - s[i]] + s[i]);
		}
	cout << dp[n][m] << endl;
	return 0;
}
