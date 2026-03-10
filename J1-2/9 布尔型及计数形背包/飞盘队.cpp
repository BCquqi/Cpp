#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int r[2005];
long long dp[2005][1005];
const int mod = 1e8;

int main(){
	int n,f;
	cin >> n >> f;
	for (int i = 1;i <= n;i++) cin >> r[i];
	dp[0][0] = 1;
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= f;j++)
		{
			dp[i][j] = dp[i - 1][j];
			dp[i][j] += dp[i - 1][(j - r[i] + f) % f];
			dp[i][j] %= mod;
		}
	cout << dp[n][0] << endl;
	return 0;
}
