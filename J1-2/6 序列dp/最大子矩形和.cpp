#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int a[405][405],s[405][405],dp[405];

int main()
{
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			cin >> a[i][j];
	for (int j = 1;j <= m;j++)
		for (int i = 1;i <= n;i++)
			s[i][j] = s[i - 1][j] + a[i][j];
	int ans = 0;
	for (int x1 = 1;x1 <= n;x1++)
		for (int x2 = 1;x2 <= m;x2++)
		{
			memset(dp,0,sizeof dp);
			for (int j = 1;j <= m;j++)
			{
				dp[j] = max(dp[j - 1],0) + s[x2][j] - s[x1 - 1][j];
				ans = max(ans,dp[j]);
			}
		}
	cout << ans << endl;
	return 0;
}
