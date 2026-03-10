#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int dp[2005][2005],mod = 1e9 + 7;

int main() {
	int n;
	cin >> n;
	dp[0][0] = 1;
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= n;j++)
		{
			dp[i][j] = dp[i - 1][j] % mod;
			if (j >= i) dp[i][j] += dp[i][j - i] % mod;
		}
	cout << dp[n][n] % mod << endl;
	return 0;
}
