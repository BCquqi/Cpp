#include<iostream>
using namespace std;

const int N = 105,M = 1005;
int a[N],b[N],c[N],dp[2][M][M];

int main()
{
	int n,m,x;
	cin >> n >> m >> x;
	for (int i = 1;i <= n;i++) cin >> a[i] >> b[i] >> c[i];
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= m;j++)
			for (int k = 0;k <= x;k++)
			{
				dp[i & 1][j][k] = dp[i - 1 & 1][j][k];
				if (j >= a[i] && k >= b[i])
					dp[i & 1][j][k] = max(dp[i & 1][j][k],dp[i - 1 & 1][j - a[i]][k - b[i]] + c[i]);
			}
	cout << dp[n & 1][m][x] << endl;
	return 0;
}
