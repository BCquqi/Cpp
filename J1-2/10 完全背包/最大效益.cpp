#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[15],b[15],dp[15][100005];

int main()
{
	int s,n,d;
	cin >> s >> n >> d;
	for (int i = 1;i <= d;i++)
	{
		cin >> a[i] >> b[i];
		a[i] /= 100;
	}
	dp[0][0] = 0;
	for (int y = 1;y <= n;y++)
	{
		int l = s / 100;
		for (int i = 1;i <= d;i++)
			for (int j = 0;j <= l;j++)
			{
				dp[i][j] = dp[i - 1][j];
				if (j >= a[i]) dp[i][j] = max(dp[i][j],dp[i][j - a[i]] + b[i]);
			}
		s += dp[d][l];
	}
	cout << s << endl;
	return 0;
}
