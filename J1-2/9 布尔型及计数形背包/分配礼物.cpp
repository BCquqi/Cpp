#include<iostream>
#include<algorithm>
using namespace std;

int a[105];
bool dp[105][10005];

int main()
{
	int n,sum = 0;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	dp[0][0] = 1;
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= sum;j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= a[i]) dp[i][j] |= dp[i - 1][j - a[i]];
		}
	int ans = 1e9;
	for (int j = 0;j <= sum / 2;j++)
		if (dp[n][j])
			ans = min(ans,abs((sum - j) - j));
	cout << ans << endl;
	return 0;
}
