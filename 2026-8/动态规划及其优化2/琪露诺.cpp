#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring> 
#define int long long
using namespace std;

const int N = 2e5 + 5;
int a[N],dp[N]; 
deque<int> q;

// dp[i] 表示琪露诺到 i 时所能获得的最大权值之和 

signed main() {
	int n,l,r,ans = -1e18;
	cin >> n >> l >> r;
	memset(dp,-0x3f,sizeof dp); // a[i] 可以为负数 
	for (int i = 0;i <= n;i++) cin >> a[i]; // 输入从 0 开始 
	dp[0] = a[0];
	for (int i = l;i <= n;i++) {
		while (!q.empty() && dp[q.back()] < dp[i - l]) q.pop_back();
		while (!q.empty() && q.front() <= i - r) q.pop_front();
		q.push_back(i - l); 
		dp[i] = dp[q.front()] + a[i];
		if (i + r > n) ans = max(ans,dp[i]);
	}
	cout << ans << endl;
	return 0;
} 