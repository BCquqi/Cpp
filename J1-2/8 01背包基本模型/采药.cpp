#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int w[105],v[105],dp[105][1005];

int main(){
	int t,m;
	cin >> t >> m;
	for (int i = 1;i <= m;i++) cin >> w[i] >> v[i];
	for (int i = 1;i <= m;i++)
		for (int j = 0;j <= t;j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= w[i]) dp[i][j] = max(dp[i][j],dp[i - 1][j - w[i]] + v[i]);
		}
	cout << dp[m][t] << endl;
	return 0;
}
