#include<iostream>
using namespace std;

const int N = 105,K = 1e5 + 5,mod = 1e9 + 7;
int a[N];
long long dp[N][K],s[K];
// dp[i][j] 表示前 i 个人，已经用掉 k 个糖的方法数 
// s[i] 记录前缀和，用于优化 

int main() {
	int n,k;
	cin >> n >> k;
	for (int i = 1;i <= n;i++) cin >> a[i];
	dp[0][0] = 1;
	for (int i = 1;i <= n;i++) {
		s[0] = dp[i - 1][0];
		for (int j = 1;j <= k;j++) s[j] = (s[j - 1] + dp[i - 1][j]) % mod;
		for (int j = 0;j <= k;j++)
			dp[i][j] = (s[j] - (j - a[i] > 0 ? s[j - a[i] - 1] : 0) + mod) % mod;
			// 理论上 s 减出来不会是负数，但 s 取模会导致其不单调递增 
	}
	cout << dp[n][k] << endl;
	return 0;
} 
