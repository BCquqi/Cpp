#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int dp[5005][5005];

int main() {
	int n,m;
	cin >> n >> m;
	string a,b;
	cin >> a >> b;
	a = '?' + a,b = '?' + b;
	dp[0][0] = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
		{
			if (a[i] == b[j]) dp[i][j] = max(dp[i][j],dp[i - 1][j - 1] + 1);
			else dp[i][j] = max(dp[i][j - 1],dp[i - 1][j]);
		}
	cout << 4 * dp[n][m] - n - m << endl;
	return 0;
}
