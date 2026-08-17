#include<iostream>
#include<queue>
#define int long long
using namespace std;

const int N = 1e6 + 5;
int x[N],s[N],dp[N],q[N]; // 上凸包 单调递减 

signed main() {
	int n,a,b,c;
	cin >> n >> a >> b >> c;
	for (int i = 1;i <= n;i++) {
		cin >> x[i];
		s[i] = s[i - 1] + x[i];
	}
	int l = 0,r = 0;
	for (int i = 1;i <= n;i++) {
		while (l < r && dp[q[l + 1]] + a * s[q[l + 1]] * s[q[l + 1]] - b * s[q[l + 1]] - dp[q[l]] - a * s[q[l]] * s[q[l]] + b * s[q[l]] > (2 * a * s[i]) * (s[q[l + 1]] - s[q[l]])) ++l;
		dp[i] = dp[q[l]] - 2 * a * s[i] * s[q[l]] + a * s[q[l]] * s[q[l]] - b * s[q[l]] + a * s[i] * s[i] + b * s[i] + c;
		while (l < r && (dp[q[r]] + a * s[q[r]] * s[q[r]] - b * s[q[r]] - dp[q[r - 1]] - a * s[q[r - 1]] * s[q[r - 1]] + b * s[q[r - 1]]) * (s[i] - s[q[r]]) <= (dp[i] + a * s[i] * s[i] - b * s[i] - dp[q[r]] - a * s[q[r]] * s[q[r]] + b * s[q[r]]) * (s[q[r]] - s[q[r - 1]])) --r; 
		q[++r] = i;
	}
	cout << dp[n] << endl;
	return 0;
}
