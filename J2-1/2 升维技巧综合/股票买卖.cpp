#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
int a[N];
long long dp[N][2];

int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++)
	{
		if (i == 1) dp[i][1] = -a[i];
		else dp[i][1] = max(dp[i - 1][1],dp[i - 2][0] - a[i]);
		if (i > 1) dp[i][0] = max(dp[i - 1][0],dp[i - 1][1] + a[i]);
		else dp[i][0] = 0;
	}
	cout << dp[n][0] << endl;
	return 0;
}
