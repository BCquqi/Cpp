#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int mod = 1e9;
int a[1005],dp[1005],sum[1005];

int main(){
	int n,s;
	cin >> n >> s;
	sum[0] = 0;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	dp[0] = 1;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= i;j++)
			if (sum[i] - sum[j - 1] <= s)
			{
				dp[i] += dp[j - 1];
				dp[i] %= mod;
			}
	cout << dp[n] % mod << endl;
	return 0;
}
