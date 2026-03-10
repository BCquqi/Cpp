#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int w[35],dp[35][20005];

int main() {
	int v,n;
	cin >> v >> n;
	for (int i = 1;i <= n;i++) cin >> w[i];
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= v;j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= w[i]) dp[i][j] = max(dp[i][j],dp[i - 1][j - w[i]] + w[i]);
		}
	cout << v - dp[n][v] << endl;
	return 0;
}
