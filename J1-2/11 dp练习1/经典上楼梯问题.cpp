#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int dp[100005],mod = 1000000007;
bool a[100005];

int main(){
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= m;i++)
	{
		int x;
		cin >> x;
		a[x] = true;
	}
	dp[0] = 1,dp[1] = !a[1];
	for (int i = 1;i <= n;i++)
	{
		if (a[i]) continue;
		dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
	}
	cout << dp[n] % mod << endl;
	return 0;
}
