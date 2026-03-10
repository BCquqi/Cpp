#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int mod = 1e9 + 7;
long long dp[2005][2005];

int main() {
	int n,k;
	cin >> n >> k;
	dp[0][0] = 1;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= k;j++)
		{
			dp[i][j] = dp[i - 1][j - 1];
			if (i > j) dp[i][j] = (dp[i][j] + dp[i - j][j]) % mod;
		}
	cout << dp[n][k] % mod << endl;
	return 0;
}
