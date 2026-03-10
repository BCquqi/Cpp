#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int sum[1005],dp[1005][1005];

int factor_sum(int x)
{
	int ret = 0;
	for (int i = 1;i * i <= x;i++)
	{
		if (x % i == 0) ret += i + x / i;
		if (i * i == x) ret -= i;
	}
	return ret - x;
}

int main() {
	int s;
	cin >> s;
	for (int i = 1;i <= s;i++) sum[i] = factor_sum(i);
	for (int i = 1;i <= s;i++)
		for (int j = 0;j <= s;j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= i) dp[i][j] = max(dp[i][j],dp[i - 1][j - i] + sum[i]);
		}
	cout << dp[s][s] << endl;
	return 0;
}
