#include<iostream>
#include<algorithm>
using namespace std;

int dp[5005][5005];

int main()
{
	int n;
	string s,t;
	cin >> n >> s;
	t = s;
	reverse(t.begin(),t.end());
	s = '?' + s,t = '?' + t;
	dp[0][0] = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
		{
			dp[i][j] = max(dp[i][j - 1],dp[i - 1][j]);
			if (s[i] == t[j]) dp[i][j] = max(dp[i][j],dp[i - 1][j - 1] + 1);
		}
	cout << n - dp[n][n] << endl;
	return 0;
}
