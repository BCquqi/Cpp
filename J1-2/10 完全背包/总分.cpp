#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int p[10005],t[10005],dp[2][10005];

int main() {
	int m,n;
	cin >> m >> n;
	for (int i = 1;i <= n;i++) cin >> p[i] >> t[i];
	dp[0][0] = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
		{
			dp[i & 1][j] = dp[i - 1 & 1][j];
			if (j >= t[i]) dp[i & 1][j] = max(dp[i & 1][j],dp[i & 1][j - t[i]] + p[i]); 
		}
	cout << dp[n & 1][m] << endl;
	return 0;
}
