#include<iostream>
using namespace std;

const int N = 5005;
int dp[N][N];
// dp[i][j] 指从 i 到 j 的最小花销 

void solve() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> x[i];
	memset(dp,0x3f,sizeof dp);
	for (int i = 1;i <= n;i++) dp[i][i] = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = i;j <= n;j++)
			dp[i][j] = min(dp[i][j],dp[i][])
	}
	return ;
}

int main() {
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
} 
