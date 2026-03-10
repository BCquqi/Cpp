#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

bool a[105][105];
int dp[105][105];

int main(){
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			cin >> a[i][j];
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
		{
			if (!a[i][j]) dp[i][j] = 0;
			else dp[i][j] = min(dp[i - 1][j - 1],min(dp[i - 1][j],dp[i][j - 1])) + 1;
		}
	int ans = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			ans = max(ans,dp[i][j]);
	cout << ans << endl;
	return 0;
}
