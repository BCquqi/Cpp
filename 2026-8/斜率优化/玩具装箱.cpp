#include<iostream>
#define int long long 
using namespace std;

const int N = 5e4 + 5;
int c[N],s[N],f[N],q[N],l,r,dp[N];

signed main() {
	int n,L;
	cin >> n >> L;
	for (int i = 1;i <= n;i++) {
		cin >> c[i];
		s[i] = s[i - 1] + c[i];
		f[i] = s[i] + i;
	}
	for (int i = 1;i <= n;i++) {
		while (l < r && (dp[q[l + 1]] + (f[q[l + 1]] + L + 1) * (f[q[l + 1]] + L + 1) - dp[q[l]] - (f[q[l]] + L + 1) * (f[q[l]] + L + 1)) <= 2 * f[i] * (f[q[l + 1]] - f[q[l]])) ++l;
		dp[i] = dp[q[l]] + (f[i] - f[q[l]] - L - 1) * (f[i] - f[q[l]] - L - 1);
		while (l < r && (dp[i] + (f[i] + L + 1) * (f[i] + L + 1) - dp[q[r]] - (f[q[r]] + L + 1) * (f[q[r]] + L + 1)) * (f[q[r]] - f[q[r - 1]]) < (dp[q[r]] + (f[q[r]] + L + 1) * (f[q[r]] + L + 1) - dp[q[r - 1]] - (f[q[r - 1]] + L + 1) * (f[q[r - 1]] + L + 1)) * (f[i] - f[q[r]])) --r;
		q[++r] = i;
	}
	cout << dp[n] << endl;
	return 0;
} 
