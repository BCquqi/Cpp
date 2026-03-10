#include<iostream>
using namespace std;

const int N = 1e5 + 5,mod = 1e9 + 7;
int dp[N];

int main()
{
	int n;
	string s;
	cin >> n >> s;
	s = '?' + s;
	for (int i = 1;i <= n;i++)
		if (s[i] == 'm' || s[i] == 'w')
		{
			cout << 0 << endl;
			return 0;
		}
	int cnt = 0;
	dp[0] = 1;
	for (int i = 1;i <= n;i++)
	{
		dp[i] = dp[i - 1];
		if (s[i] == s[i - 1] && (s[i] == 'n' || s[i] == 'v')) dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
	}
	cout << dp[n] % mod << endl;
	return 0;
}