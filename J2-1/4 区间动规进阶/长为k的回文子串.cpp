#include<iostream>
using namespace std;

const int N = 5005;
bool dp[N][N];

int main()
{
	string s;
	cin >> s;
	int n = s.size();
	s = '?' + s;
	for (int i = 1;i <= n;i++)
	{
		dp[i][i] = true;
		if (s[i] == s[i - 1]) dp[i - 1][i] = true;
	}
	for (int len = 1;len <= n;len++)
	{
		int ans = 0;
		for (int i = 1;i + len - 1 <= n;i++)
		{
			int j = i + len - 1;
			if (s[i] == s[j] && len != 1 && len != 2) dp[i][j] |= dp[i + 1][j - 1];
			if (dp[i][j]) ans++;
		}
		cout << ans << ' ';
	}
	cout << endl;
	return 0;
}