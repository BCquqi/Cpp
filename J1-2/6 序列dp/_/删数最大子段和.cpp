#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

int a[1005],dp[1005];

int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	int ans = -1e9;
	for (int t = 1;t <= n;t++)
	{
		memset(dp,-0x3f, sizeof dp);
		int tmp = -1e9;
		for (int i = 1;i <= n;i++)
		{
			if (i == t) continue;
			else if (i == t + 1)
				dp[i] = max(dp[i - 2] + a[i],a[i]),tmp = max(tmp,dp[i]);
			else
				dp[i] = max(dp[i - 1] + a[i],a[i]),tmp = max(tmp,dp[i]);
		}
		ans = max(ans,tmp);
	}
	cout << ans << endl;
	return 0;
}
