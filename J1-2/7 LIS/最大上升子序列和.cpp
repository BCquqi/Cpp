#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int a[1005];
long long dp[1005];	

int main(){
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++)
		for (int j = 0;j < i;j++)
			if (a[j] < a[i])
				dp[i] = max(dp[i],dp[j] + a[i]);
	long long ans = 0;
	for (int i = 1;i <= n;i++) ans = max(ans,dp[i]);
	cout << ans << endl;
	return 0;
}
