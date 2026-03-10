#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int a[1005][1005],dp[1005][1005];

int main(){
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			cin >> a[i][j];
	memset(dp,-0x3f,sizeof dp);
	dp[0][0] = 0;
	for (int j = 1;j <= m;j++)
		for (int i = 1;i <= n;i++)
			dp[i][j] = max(max(dp[i - 1][j],dp[i][j - 1]),max(dp[i + 1][j - 1],dp[i - 1][j - 1])) + a[i][j];
	cout << dp[n][m] << endl;
	return 0;
}
