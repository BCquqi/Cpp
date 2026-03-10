#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 405;
int dp[N][N];

int main(){
	string s;
	cin >> s;
	int n = s.size();
	s = '?' + s;
	for (int i = 1;i <= n;i++) dp[i][i] = 1;
	for (int len = 2;len <= n;len++)
		for (int i = 1;i + len - 1 <= n;i++)
		{
			int j = i + len - 1;
			dp[i][j] = dp[i + 1][j] + 1;
			for (int k = i + 1;k <= j;k++)
				if (s[i] == s[k]) dp[i][j] = min(dp[i][j],dp[i + 1][k] + dp[k + 1][j]);
		}
	cout << dp[1][n] << endl;
	return 0;
}