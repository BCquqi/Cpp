#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int mod = 1e9 + 7;
int dp[100005][15];

int main(){
	int n,m,d;
	cin >> n >> m >> d;
	for (int i = 1;i <= m;i++) dp[1][i] = 1;
	for (int i = 2;i <= n;i++)
		for (int j = 1;j <= m;j++)
			for (int k = 1;k <= m;k++)
				if (abs(j - k) <= d)
					dp[i][j] += dp[i - 1][k],dp[i][j] %= mod;
	long long ans = 0;
	for (int i = 1;i <= m;i++) ans += dp[n][i],ans %= mod;
	cout << ans << endl;
	return 0;
}
