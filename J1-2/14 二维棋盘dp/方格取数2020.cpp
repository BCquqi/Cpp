#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

long long a[1005][1005],dp[1005][1005][3];

int main(){
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			cin >> a[i][j];
	memset(dp,-0x3f,sizeof dp);
	dp[1][0][0] = 0,dp[0][1][0] = 0;
	for (int j = 1;j <= m;j++)
	{
		for (int i = 1;i <= n;i++)
		{
			dp[i][j][2] = max(dp[i - 1][j][2],dp[i - 1][j][0]) + a[i][j];
			dp[i][j][0] = max(dp[i][j - 1][0],max(dp[i][j - 1][1],dp[i][j - 1][2])) + a[i][j];
		}
		for (int i = n;i >= 1;i--)
			dp[i][j][1] = max(dp[i + 1][j][0],dp[i + 1][j][1]) + a[i][j];
	}
	cout << max(dp[n][m][0],dp[n][m][2]) << endl;
	return 0;
}
