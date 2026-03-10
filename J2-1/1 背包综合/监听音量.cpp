#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 120;
int v[N],a[N],d[N],dp[100005];

int main() {
	int n,b;
	cin >> n >> b;
	for (int i = 1;i <= b;i++) cin >> v[i];
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (a[i - 1] > 0) d[i] = a[i] - a[i - 1] + 1;
		else d[i] = a[i];
	}
	memset(dp,0x3f,sizeof dp);
	dp[0] = 0;
	for (int i = 1;i <= b;i++)
		for (int j = v[i];j <= 1e5;j++)
			dp[j] = min(dp[j],dp[j - v[i]] + 1);
	int ans = 0;
	for (int i = 1;i <= n;i++)
	{
		if (d[i] < 0 || dp[d[i]] > 1e9)
		{
			cout << -1 << endl;
			return 0;
		}
		ans += dp[d[i]];
	}
	cout << ans << endl;
	return 0;
}
