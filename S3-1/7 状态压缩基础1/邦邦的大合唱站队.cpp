#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5,M = 20;
int a[N],s[N][M],dp[(1 << M) + 5];

int main() {
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		for (int j = 1;j <= m;j++) s[i][j] = s[i - 1][j];
		s[i][a[i]]++;
	}
	memset(dp,0x3f,sizeof dp);
	dp[0] = 0;
	for (int i = 0;i < (1 << m);i++) {
		int L = 0;
		for (int j = 0;j < m;j++)
			if ((i >> j) & 1) L += s[n][j + 1];
		L++; // 新队伍起点
		for (int j = 0;j < m;j++) {
			if ((i >> j) & 1) continue;
			int R = L + s[n][j + 1] - 1;
			dp[i | (1 << j)] = min(dp[i | (1 << j)],dp[i] + s[n][j + 1] - (s[R][j + 1] - s[L - 1][j + 1]));
		}
	}
	cout << dp[(1 << m) - 1] << endl;
	return 0;
}