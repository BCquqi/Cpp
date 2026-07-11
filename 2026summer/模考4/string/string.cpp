#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

const int N = 130,M = 2005;
int cost[N],dp[M][M];

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m;
	string s;
	cin >> n >> m >> s;
	s = '?' + s;
	for (int i = 1;i <= n;i++) {
		char c;
		int a,b;
		cin >> c >> a >> b;
		cost[c] = min(a,b);
	}
	memset(dp,0x3f,sizeof dp);
	for (int i = 1;i <= m;i++) dp[i][i] = 0,dp[i + 1][i] = 0;
	for (int len = 2;len <= m;len++)
		for (int l = 1;l + len - 1 <= m;l++) {
			int r = l + len - 1;
			dp[l][r] = min(dp[l][r - 1] + cost[s[r]],dp[l + 1][r] + cost[s[l]]);
			if (s[l] == s[r]) dp[l][r] = min(dp[l][r],dp[l + 1][r - 1]);
		}
	cout << dp[1][m] << endl;
	return 0;
}
