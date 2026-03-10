#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

const int N = 100005;
int t[N],dp[N],f1[N],f2[N];

int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> t[i];
	int ans = 0;
	for (int i = 1;i <= n;i++)
	{
		int pos = lower_bound(dp + 1,dp + ans + 1,t[i]) - dp;
		dp[pos] = t[i];
		ans = max(ans,pos);
		f1[i] = ans;
	}
	ans = 0;
	memset(dp,0,sizeof dp);
	for (int i = n;i >= 1;i--)
	{
		int pos = lower_bound(dp + 1,dp + ans + 1,t[i]) - dp;
		dp[pos] = t[i];
		ans = max(ans,pos);
		f2[i] = ans;
	}
	int maxn = 0;
	for (int i = 1;i <= n;i++) maxn = max(maxn,f1[i] + f2[i] - 1);
	cout << n - maxn << endl;
	return 0;
}
