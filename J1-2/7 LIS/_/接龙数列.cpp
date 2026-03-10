#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int dp[5005];
string a[5005];

int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++)
	{
		dp[i] = 1;
		for (int j = 0;j < i;j++)
			if (a[j][a[j].size() - 1] == a[i][0])
				dp[i] = max(dp[i],dp[j] + 1);
	}
	int ans = 0;
	for (int i = 1;i <= n;i++) ans = max(ans,dp[i]);
	cout << n - ans << endl;
	return 0;
}
