#include<iostream>
using namespace std;

const int N = 65,M = 1205;
int a[N],v[N],dp[2][M][M];

int main()
{
	int n,T;
	cin >> n >> T;
	for (int i = 1;i <= n;i++) cin >> a[i] >> v[i];
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= T;j++)
			for (int k = 0;k <= T;k++)
			{
				dp[i & 1][j][k] = dp[i - 1 & 1][j][k];
				if (j >= a[i])
					dp[i & 1][j][k] = max(dp[i & 1][j][k],dp[i - 1 & 1][j - a[i]][k] + v[i]);
				if (k >= a[i])
					dp[i & 1][j][k] = max(dp[i & 1][j][k],dp[i - 1 & 1][j][k - a[i]] + v[i]);
			}
	cout << dp[n & 1][T][T] << endl;
	return 0;
}
