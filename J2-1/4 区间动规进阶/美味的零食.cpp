#include<iostream>
using namespace std;

const int N = 2005;
int v[N],s[N],dp[N][N];

int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> v[i],s[i] = s[i - 1] + v[i],dp[i][i] = v[i];
	for (int len = 2;len <= n;len++)
		for (int i = 1;i + len - 1 <= n;i++)
		{
			int j = i + len - 1;
			dp[i][j] = max(dp[i + 1][j] + v[i] + s[j] - s[i],dp[i][j - 1] + v[j] + s[j - 1] - s[i - 1]);
		}
	cout << dp[1][n] << endl;
	return 0;
}
