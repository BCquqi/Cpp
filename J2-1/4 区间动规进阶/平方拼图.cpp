#include<iostream>
using namespace std;

const int N = 105;
int a[N],dp[N][N];

int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int len = 3;len <= n + 2;len++)
		for (int i = 0;i + len - 1 <= n + 1;i++)
		{
			int j = i + len - 1;
			for (int k = i + 1;k <= j - 1;k++)
				dp[i][j] = max(dp[i][j],dp[i][k] + dp[k][j] + (a[i] + a[k] + a[j]) * (a[i] + a[k] + a[j]));
		}
	cout << dp[0][n + 1] << endl;
	return 0;
}
