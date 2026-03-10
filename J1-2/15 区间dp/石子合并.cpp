#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

int a[105],s[105],dp[105][105],dp2[105][105];

int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	memset(dp2,0x3f,sizeof dp2);
	for (int i = 1;i <= n;i++) dp2[i][i] = 0;
	for (int len = 2;len <= n;len++)
		for (int i = 1;i + len - 1 <= n;i++)
		{
			int j = i + len - 1;
			for (int k = i;k < j;k++)
			{
				dp[i][j] = max(dp[i][j],dp[i][k] + dp[k + 1][j] + s[j] - s[i - 1]);
				dp2[i][j] = min(dp2[i][j],dp2[i][k] + dp2[k + 1][j] + s[j] - s[i - 1]);
			}
		}
	cout << dp2[1][n] << endl << dp[1][n] << endl;
	return 0;
}
