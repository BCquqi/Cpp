#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int w[105],p[105],dp[2][5000005];

int main(){
	int n,W;
	cin >> n >> W;
	for (int i = 1;i <= n;i++) cin >> w[i] >> p[i];
	dp[0][0] = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= 50000;j++)
		{
			dp[i & 1][j] = dp[i - 1 & 1][j];
			if (j >= p[i]) dp[i & 1][j] = max(dp[i & 1][j],dp[i & 1][j - p[i]] + w[i]);
		}
	for (int j = 1;j <= 50000;j++)
		if (dp[n & 1][j] >= W)
		{
			cout << j << endl;
			return 0;
		}
	return 0;
}
