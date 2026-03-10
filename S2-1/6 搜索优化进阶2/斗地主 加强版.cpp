#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 30;
int T,n,s[N],c[N],ans,dp[N][N][N][N];

void init() {
	memset(dp,0x3f,sizeof dp);
	dp[0][0][0][0] = 0;
	for (int d = 0;d <= 25;d++)
		for (int c = 0;c <= 25;c++)
			for (int b = 0;b <= 25;b++)
				for (int a = 0;a <= 25;a++) {
					int tmp = 0x3f3f3f;
					if (a) tmp = min(tmp,dp[a - 1][b][c][d] + 1);
					if (b) tmp = min(tmp,dp[a][b - 1][c][d] + 1);
					if (c) tmp = min(tmp,dp[a][b][c - 1][d] + 1);
					if (d) tmp = min(tmp,dp[a][b][c][d - 1] + 1);
					if (a > 1 && d) tmp = min(tmp,dp[a - 2][b][c][d - 1] + 1);
					if (b > 1 && d) tmp = min(tmp,dp[a][b - 2][c][d - 1] + 1);
					if (b && d) tmp = min(tmp,dp[a][b - 1][c][d - 1] + 1);
					if (a && c) tmp = min(tmp,dp[a - 1][b][c - 1][d] + 1);
					if (b && c) tmp = min(tmp,dp[a][b - 1][c - 1][d] + 1);
					if (b) tmp = min(tmp,dp[a + 2][b - 1][c][d]);
					if (c) tmp = min(tmp,dp[a + 1][b + 1][c - 1][d]);
					if (d) tmp = min(tmp,min(dp[a][b + 2][c][d - 1],dp[a + 1][b][c + 1][d - 1]));
					dp[a][b][c][d] = min(dp[a][b][c][d],tmp);
				}
}

void dfs(int x) {
	if (x >= ans) return ;
	memset(c,0,sizeof c);
	for (int i = 2;i <= 14;i++) c[s[i]]++;
	ans = min(ans,x + dp[c[1] + s[0]][c[2]][c[3]][c[4]]);
	if (s[0] == 2) ans = min(ans,x + dp[c[1]][c[2]][c[3]][c[4]] + 1);
	for (int a = 1;a <= 3;a++)
		for (int i = 3;i <= 14;i++) {
			int cnt = 0;
			for (int j = i;j <= 14;j++) {
				if (s[j] >= a) cnt++;
				else break;
				if (a * cnt >= 5) {
					for (int k = i;k <= j;k++) s[k] -= a;
					dfs(x + 1);
					for (int k = i;k <= j;k++) s[k] += a;
				}
			}
		}
}

void solve() {
	memset(s,0,sizeof s);
	for (int i = 1;i <= n;i++) {
		int a,b;
		cin >> a >> b;
		s[a]++;
	}
	s[14] = s[1];
	ans = n;
	dfs(0);
	cout << ans << endl;
	return ;
}

int main(){
	cin >> T >> n;
	init();
	while (T--) solve();
	return 0;
}