#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

bool dp[55][1005];
int c[55];

int main() {
	int n,bl,ml;
	cin >> n >> bl >> ml;
	for (int i = 1;i <= n;i++) cin >> c[i];
	dp[0][bl] = true;
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= ml;j++)
		{
			if (j >= c[i]) dp[i][j] |= dp[i - 1][j - c[i]];
			if (j + c[i] <= ml) dp[i][j] |= dp[i - 1][j + c[i]];
		}
	for (int j = ml;j >= 0;j--)
		if (dp[n][j])
		{
			cout << j << endl;
			return 0;
		}
	cout << -1 << endl;
	return 0;
}
