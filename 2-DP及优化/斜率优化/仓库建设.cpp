#include<iostream>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;

const int N = 1e6 + 5;
int x[N],p[N],c[N],s1[N],s2[N],dp[N],q[N];
//  距离 数量 费用   维护用          队列 

signed main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> x[i] >> p[i] >> c[i];
		s1[i] = s1[i - 1] + p[i], s2[i] = s2[i - 1] + p[i] * x[i]; 
	}
	int l = 1,r = 1;
	for (int i = 1;i <= n;i++) {
		while (l < r && dp[q[l + 1]] + s2[q[l + 1]] - dp[q[l]] - s2[q[l]] <= x[i] * (s1[q[l + 1]] - s1[q[l]])) ++l;
		dp[i] = dp[q[l]] + c[i] + x[i] * (s1[i] - s1[q[l]]) - (s2[i] - s2[q[l]]);
		if (!p[i]) dp[i] = min(dp[i],dp[i - 1]);
		while (l < r && (dp[q[r]] + s2[q[r]] - dp[q[r - 1]] - s2[q[r - 1]]) * (s1[i] - s1[q[r]]) >= (dp[i] + s2[i] - dp[q[r]] - s2[q[r]]) * (s1[q[r]] - s1[q[r - 1]])) --r;
		q[++r] = i;
	}
	int ans = 1e18,i;
	// 答案逻辑: 所有货流流向 n, 最后一个有货工厂或者后续的没货工厂都可以且必须选择建一个仓库 
	for (i = n;!p[i] && i >= 1;i--)
		ans = min(ans,dp[i]);
	ans = min(ans,dp[i]);
	cout << ans << endl;
	return 0;
}