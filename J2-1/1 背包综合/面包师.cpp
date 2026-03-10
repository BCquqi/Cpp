#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 15;
int a[N],b[N],c[N],d[N],dp[N][1005];

int main() {
	int n,m;
	cin >> n >> m >> c[0] >> d[0];
	for (int i = 1;i <= m;i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
	for (int i = 1;i <= m;i++)
		for (int j = 0;j <= n;j++)
			for (int k = 0;k <= a[i] / b[i] && k <= j / c[i];k++)
				dp[i][j] = max(dp[i][j],dp[i - 1][j - k * c[i]] + k * d[i]);
	int ans = 0;
	for (int j = 0;j <= n;j++)
		ans = max(ans,dp[m][j] + (n - j) / c[0] * d[0]);
	cout << ans << endl;
	return 0;
}
