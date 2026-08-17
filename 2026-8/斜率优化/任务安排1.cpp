#include<iostream>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;

const int N = 3e5 + 5;
int t[N],c[N],st[N],sc[N],dp[N],q[N],l = 1,r = 1; // 这里手写单调队列简单 
// dp[i] 表示前 i 个任务的最小费用总和 

signed main() {
	int n,s;
	cin >> n >> s;
	for (int i = 1;i <= n;i++) {
		cin >> t[i] >> c[i];
		st[i] = st[i - 1] + t[i], sc[i] = sc[i - 1] + c[i];
	}
	memset(dp,0x3f,sizeof dp);
	dp[0] = 0;
	q[1] = dp[0];
	for (int i = 1;i <= n;i++) {
		while (l < r && (dp[q[l + 1]] - dp[q[l]]) <= (s + st[i]) * (sc[q[l + 1]] - sc[q[l]])) ++l;
		dp[i] = dp[q[l]] + s * (sc[n] - sc[q[l]]) + st[i] * (sc[i] - sc[q[l]]);
		while (l < r && (dp[q[r]] - dp[q[r - 1]]) * (sc[i] - sc[q[r]]) >= (dp[i] - dp[q[r]]) * (sc[q[r]] - sc[q[r - 1]])) --r;
		q[++r] = i;
	}
	cout << dp[n] << endl; 
	return 0;
}
