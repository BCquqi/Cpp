#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int a[1005];
bool dp[2][500005];

int main()
{
	int n,sum = 0;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	if (sum % 2 == 1)
	{
		cout << "No" << endl;
		return 0;
	}
	dp[0][0] = 1,sum /= 2;
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= sum;j++)
		{
			dp[i & 1][j] = dp[i - 1 & 1][j];
			if (j >= a[i]) dp[i & 1][j] |= dp[i - 1 & 1][j - a[i]];
		}
	if (dp[n & 1][sum]) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
