#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int v[5005],dp[2][50005];

int main()
{
	int c,h;
	cin >> c >> h;
	for (int i = 1;i <= h;i++) cin >> v[i];
	for (int i = 1;i <= h;i++)
		for (int j = 0;j <= c;j++)
		{
			dp[i & 1][j] = dp[i - 1 & 1][j];
			if (j >= v[i])
				dp[i & 1][j] = max(dp[i & 1][j],dp[i - 1 & 1][j - v[i]] + v[i]);
		}
	cout << dp[h & 1][c] << endl;
	return 0;
}
