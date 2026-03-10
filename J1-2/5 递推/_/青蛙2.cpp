#include<iostream>
#include<cmath>
using namespace std;

int h[100005],dp[100005];

int main()
{
	int n,k;
	cin >> n >> k;
	for (int i = 1;i <= n;i++) cin >> h[i];
	dp[1] = 0;
	for (int i = 2;i <= n;i++)
	{
		int maxn = 1e9;
		for (int j = 1;j <= k;j++)
		{
			if (i < j + 1) break;
			maxn = min(maxn,dp[i - j] + abs(h[i] - h[i - j]));
		}
		dp[i] = maxn;
	}
	cout << dp[n] << endl;
	return 0;
}
