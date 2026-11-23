#include<iostream>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;

const int N = 1e7 + 5;
int dp[N];

void solve() {
	int n,x,y,z;
	cin >> n >> x >> y >> z;
	memset(dp,0x3f,sizeof dp);
	dp[0] = 0;
	for (int i = 1;i <= n;i++) {
		int point = 0;
		for (int j = 1;j <= i;j++) {
			if (dp[i] < max(i * x,dp[j - 1]) + y + z * (i - j + 1))
				dp[i] = max(i * x,dp[j - 1]) + y + z * (i - j + 1),point = j;
		}
		cout << point << endl;
	}
		
			
	cout << dp[n] << endl;
	return ;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
//	freopen("pipeline.in","r",stdin);
//	freopen("pipeline.out","w",stdout);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}
