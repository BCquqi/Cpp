#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 85,M = 80 * 80;
bool dp[81][81][2 * M + 1];
int a[N][N],b[N][N];

int main(){
	int h,w;
	cin >> h >> w;
	for (int i = 1;i <= h;i++)
		for (int j = 1;j <= w;j++)
			cin >> a[i][j];
	for (int i = 1;i <= h;i++)
		for (int j = 1;j <= w;j++)
			cin >> b[i][j];
	memset(dp,false,sizeof dp);
	dp[0][1][M] = dp[1][0][M] = true;
	for (int i = 1;i <= h;i++)
		for (int j = 1;j <= w;j++)
			for (int k = -M;k <= M;k++)
			{
				int t = a[i][j] - b[i][j];
				if (M + k - t >= 0 && k + M - t <= 2 * M)
					dp[i][j][k + M] |= dp[i - 1][j][M + k - t],
					dp[i][j][k + M] |= dp[i][j - 1][M + k - t];
				if (M + k + t <= 2 * M && k + M + t >= 0)
					dp[i][j][k + M] |= dp[i - 1][j][M + k + t],
					dp[i][j][k + M] |= dp[i][j - 1][M + k + t];
			}
	for (int t = 0;t <= M;t++)
		if (dp[h][w][M + t] || dp[h][w][M - t])
		{
			cout << t << endl;
			return 0;
		}
	return 0;
}
