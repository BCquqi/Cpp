#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 105;
int w[N],v[N],dp[N][100005];

int main() {
	int n,W,sum = 0;
	cin >> n >> W;
	for (int i = 1;i <= n;i++)
	{
		cin >> w[i] >> v[i];
		sum += v[i];
	}
	memset(dp,0x3f,sizeof dp);
	dp[0][0] = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= sum;j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= v[i]) dp[i][j] = min(dp[i][j],dp[i - 1][j - v[i]] + w[i]);
		}
	int ans = 0;
	for (int j = 0;j <= sum;j++)
		if (dp[n][j] <= W) ans = j;
	cout << ans << endl;
	return 0;
}
