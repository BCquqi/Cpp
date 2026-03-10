#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int c[3005],d[3005],dp[3005][3005];

int main() {
	int k,l;
	cin >> k >> l;
	for (int i = 1;i <= k;i++) cin >> c[i];
	for (int i = 1;i <= l;i++) cin >> d[i];
	memset(dp,0x3f,sizeof dp);
	for (int i = 1;i <= k;i++) dp[i][0] = i;
	for (int j = 1;j <= l;j++) dp[0][j] = j;
	dp[0][0] = 0;
	for (int i = 1;i <= k;i++)
		for (int j = 1;j <= l;j++)
		{
			dp[i][j] = min(dp[i - 1][j] + 1,dp[i][j - 1] + 1);
			if (c[i] == d[j]) dp[i][j] = min(dp[i][j],dp[i - 1][j - 1] + 1);
		}
	cout << dp[k][l] << endl;
	return 0;
}
