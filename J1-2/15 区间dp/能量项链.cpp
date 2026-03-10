#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int t[205],w[205],dp[205][205];

int main(){
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> t[i];
	for (int i = 1;i <= n;i++) w[i] = t[i + 1];
	w[n] = t[1];
	for (int i = 1;i <= n;i++) t[i + n] = t[i],w[i + n] = w[i];
	for (int len = 2;len <= n;len++)
		for (int i = 1;i + len - 1 <= 2 * n;i++)
		{
			int j = i + len - 1;
			for (int k = i;k < j;k++)
				dp[i][j] = max(dp[i][j],dp[i][k] + dp[k + 1][j] + t[i] * w[k] * w[j]);
		}
	int ans = 0;
	for (int i = 1;i <= n;i++) ans = max(ans,dp[i][i + n - 1]);
	cout << ans << endl;
	return 0;
}
