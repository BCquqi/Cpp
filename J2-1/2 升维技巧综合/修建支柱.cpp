#include<iostream>
#include<cstring>
using namespace std;

const int M = 6e4,N = 2 * M + 5,W = 125;
int h[W],v[W],dp[W][N];

int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> h[i];
	for (int i = 1;i <= n;i++) cin >> v[i];
	memset(dp,-0x3f,sizeof dp);
	dp[0][M] = 0;
	for (int i = 1;i <= n;i++)
		for (int j = -M;j <= M;j++)
		{
			dp[i][M + j] = max(dp[i][M + j],dp[i - 1][M + j]);
			if (M + j >= h[i]) dp[i][M + j] = max(dp[i][M + j],dp[i - 1][M + j - h[i]] + v[i]);
			if (M + j + h[i] <= 2 * M) dp[i][M + j] = max(dp[i][M + j],dp[i - 1][M + j + h[i]] + v[i]);
		}
	cout << dp[n][M] << endl;
	return 0;
}