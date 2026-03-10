#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[20];
bool dp[20][100005];

int main() {
	int n,g = 0;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		g = __gcd(g,a[i]);
	}
	if (g != 1)
	{
		cout << 0 << endl;
		return 0;
	}
	dp[0][0] = true;
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= 1e5;j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= a[i]) dp[i][j] |= dp[i][j - a[i]];
		}
	for (int i = 1e5;i >= 0;i--)
		if (!dp[n][i])
		{
			cout << i << endl;
			return 0;
		}
	cout << 0 << endl;
	return 0;
}
