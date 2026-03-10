#include<iostream>
using namespace std;

const int N = 5005;
int dp[N][N],ans[N],cnt[N];

int main()
{
	string s;
	cin >> s;
	int n = s.size();
	s = '?' + s;
	for (int i = 1;i <= n;i++)
	{
		dp[i][i] = 1,cnt[1]++;
		if (s[i] == s[i - 1]) dp[i - 1][i] = 2,cnt[2]++;
	}
	for (int len = 3;len <= n;len++)
		for (int i = 1;i + len - 1 <= n;i++)
		{
			int j = i + len - 1;
			if (s[i] == s[j] && dp[i + 1][j - 1] > 0)
				dp[i][j] = dp[i][i + len / 2 - 1] + 1;
			cnt[dp[i][j]]++;
		}
	for (int i = n;i >= 1;i--) ans[i] = ans[i + 1] + cnt[i];
	for (int i = 1;i <= n;i++) cout << ans[i] << ' ';
	cout << endl;
	return 0;
}