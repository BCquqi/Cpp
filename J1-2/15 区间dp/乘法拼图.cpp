#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int a[105],dp[105][105];

int main(){
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	a[0] = 1,a[n + 1] = 1;
	memset(dp,0x3f,sizeof dp);
	for (int i = 1;i <= n;i++) dp[i][i] = 0,dp[i][i + 1] = 0;
	for (int len = 3;len <= n;len++)
		for (int i = 1;i + len - 1 <= n;i++)
		{
			int j = i + len - 1;
			for (int k = i + 1;k < j;k++)
				dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j] + a[i] * a[j] * a[k]);
		}
	cout << dp[1][n] << endl;
	return 0;
}
