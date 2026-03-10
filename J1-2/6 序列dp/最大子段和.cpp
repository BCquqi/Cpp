#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

long long a[100005],sum[100005],dp[100005];

int main(){
	int n;
	cin >> n;
	sum[0] = 0;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	long long ans = 0;
	for (int i = 1;i <= n;i++) dp[i] = max(dp[i - 1] + a[i],a[i]),ans = max(ans,dp[i]);
	cout << ans << endl;
	return 0;
}
