#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int w[1005],v[1005],dp[1005][1005];

int main() {
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> w[i] >> v[i];
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= m;j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= w[i]) dp[i][j] = max(dp[i][j],dp[i - 1][j - w[i]] + v[i]);
		}
	cout << dp[n][m] << endl;
	return 0;
}
