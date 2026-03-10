#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int v[30],p[30],dp[30][30005];

int main(){
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= m;i++) cin >> v[i] >> p[i];
	for (int i = 1;i <= m;i++)
		for (int j = 0;j <= n;j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= v[i]) dp[i][j] = max(dp[i][j],dp[i - 1][j - v[i]] + p[i] * v[i]);
		}
	cout << dp[m][n] << endl;
	return 0;
}
