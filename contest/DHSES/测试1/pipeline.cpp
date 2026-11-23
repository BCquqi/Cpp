#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#define int long long
using namespace std;

const int N = 1e7 + 5;
int dp[N],q[N];

void solve() {
	int n,x,y,z;
	cin >> n >> x >> y >> z;
	for (int i = 1;i <= n;i++) dp[i] = 1e18;
	dp[0] = 0;
	int cur = 1,l = 1,r = 0;
	for (int i = 1;i <= n;i++) {
		while (l <= r && dp[q[r] - 1] + y + z * (-q[r] + 1) >= dp[i - 1] + y + z * (-i + 1)) r--;
		q[++r] = i;
		while (cur <= i && dp[cur - 1] <= i * x) cur++;
		if (cur != 1) dp[i] = min(dp[i],i * x + y + z * (i - cur + 2));
		while (l <= r && q[l] < cur) l++;
		if (l <= r) dp[i] = min(dp[i],dp[q[l] - 1] + y + z * (-q[l] + 1) + z * i);
	}
	cout << dp[n] << '\n';
	return ;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("pipeline.in","r",stdin);
	freopen("pipeline.out","w",stdout);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}
