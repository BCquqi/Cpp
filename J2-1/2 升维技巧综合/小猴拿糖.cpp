#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1e5 + 5;
int a[N],dp[N][2];

void solve()
{
	memset(dp,0,sizeof dp);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++)
		dp[i][0] = max(dp[i - 1][0],dp[i - 1][1]),dp[i][1] = dp[i - 1][0] + a[i];
	cout << max(dp[n][0],dp[n][1]) << endl;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}
