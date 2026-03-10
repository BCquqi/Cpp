#include<iostream>
#include<cstdio>
using namespace std;

long long dp[1605][1605];

int main() {
	int n;
	cin >> n;
	if ((n * (n + 1)) % 4 != 0)
	{
		cout << 0 << endl;
		return 0;
	}
	dp[0][0] = 1;
	int sum = n * (n + 1) / 4;
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= sum;j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= i) dp[i][j] += dp[i - 1][j - i];
		}
	cout << dp[n][sum] / 2 << endl;
	return 0;
}
