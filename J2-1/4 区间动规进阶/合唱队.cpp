#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int mod = 19650827,N = 1005;
int a[N],dp[N][N][2];

int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i],dp[i][i][0] = 1;
	for (int len = 2;len <= n;len++)
		for (int i = 1;i + len - 1 <= n;i++)
		{
			int j = i + len - 1;
			if (a[i] < a[i + 1]) dp[i][j][0] += dp[i + 1][j][0],dp[i][j][0] %= mod;
			if (a[i] < a[j]) dp[i][j][0] += dp[i + 1][j][1],dp[i][j][0] %= mod;
			if (a[j] > a[j - 1]) dp[i][j][1] += dp[i][j - 1][1],dp[i][j][1] %= mod;
			if (a[j] > a[i]) dp[i][j][1] += dp[i][j - 1][0],dp[i][j][1] %= mod;
		}
	cout << (dp[1][n][0] + dp[1][n][1]) % mod << endl;
    return 0;
}