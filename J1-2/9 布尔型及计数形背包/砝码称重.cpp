#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

bool dp[1005][1005];
int a[10],w[1005];
int wei[7] = {0,1,2,3,5,10,20};

int main() {
	int cur = 0;
	for (int i = 1;i <= 6;i++)
	{
		cin >> a[i];
		for (int j = 1;j <= a[i];j++) w[++cur] = wei[i];
	}
	dp[0][0] = true;
	for (int i = 1;i <= cur;i++)
		for (int j = 0;j <= 1000;j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= w[i]) dp[i][j] |= dp[i - 1][j - w[i]];
		}
	int ans = 0;
	for (int j = 1;j <= 1000;j++)
		if (dp[cur][j]) ans++;
	cout << ans << endl;
	return 0;
}
