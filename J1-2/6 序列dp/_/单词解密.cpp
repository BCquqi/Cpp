#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int mod = 1e9 + 7;
int dp[100005];
// dp[i]表示前i个字符的可能解密情况数

int main()
{
	string s;
	cin >> s;
	int n = s.size();
	s = '?' + s;
	dp[0] = 1,dp[1] = 1;
	for (int i = 2;i <= n;i++)
	{
		int num = (s[i - 1] - '0') * 10 + (s[i] - '0');
		dp[i] += dp[i - 1],dp[i] %= mod;
		if (s[i] == '0') dp[i] -= dp[i - 1];
		if (num >= 10 && num <= 26) dp[i] += dp[i - 2],dp[i] %= mod;
	}
	cout << dp[n] % mod << endl;
	return 0;
}
