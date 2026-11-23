#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int a[1005],mod = 1e9 + 7;
int dp[1005][20005];

int main()
{
	int n,m,sum = 0;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	dp[0][sum] = 1;
	for (int i = 1;i <= n;i++)
		for (int j = -sum;j <= sum;j++)
		{
			if (j - a[i] >= -sum) dp[i][j + sum] = (dp[i - 1][j - a[i] + sum] + dp[i][j + sum]) % mod;
			if (j + a[i] <= m + sum) dp[i][j + sum] = (dp[i - 1][j + a[i] + sum] + dp[i][j + sum]) % mod;
		}
	cout << dp[n][m + sum] << endl;
	return 0;
}
