#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int dp[405][405][2];

int main() {
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	s = '?' + s;
	memset(dp,0x3f,sizeof dp);
	dp[0][0][0] = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= i;j++)
		{
			dp[i][j][0] = min(dp[i - 1][j][0],dp[i - 1][j][1]);
			if (s[i] == '1')
				for (int t = 1;t <= j && s[i - t + 1] == '1';t++)
					dp[i][j][1] = min(dp[i][j][1],dp[i - t][j - t][0] + t * (t + 1) / 2);
		}
	for (int j = n;j >= 0;j--)
	{
		if (dp[n][j][1] <= k)
		{
			cout << j << endl;
			return 0;
		}
		if (dp[n][j][0] <= k)
		{
			cout << j << endl;
			return 0;
		}
	}
	return 0;
}
