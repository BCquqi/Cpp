#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int a[250],dp[250][250];

int main(){
	int n;
	cin >> n;
	x
	for (int len = 2;len <= n;len++)
		for (int i = 1;i + len - 1 <= n;i++)
		{
			int j = i + len - 1;
			for (int k = i;k < j;k++)
				if (dp[i][k] == dp[k + 1][j])
					dp[i][j] = max(dp[i][j],dp[i][k] + 1);
		}
	int ans = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			ans = max(ans,dp[i][j]);
	cout << ans << endl;
	return 0;
}
