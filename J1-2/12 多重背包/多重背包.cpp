#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e4 + 5;
int v[N],w[N],m[N],dp[N][1005];

int main(){
	int n,W;
	cin >> n >> W;
	for (int i = 1;i <= n;i++) cin >> v[i] >> w[i] >> m[i];
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= W;j++)
			for (int t = 0;t <= m[i];t++)
				if (j >= t * w[i])
					dp[i][j] = max(dp[i][j],dp[i - 1][j - t * w[i]] + t * v[i]);
	cout << dp[n][W] << endl;
	return 0;
}
