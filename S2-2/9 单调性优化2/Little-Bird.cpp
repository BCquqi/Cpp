#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int N = 1e6 + 5;
int d[N],dp[N],n;

void solve() {
	memset(dp,0x3f,sizeof dp);
	dp[1] = 0;
	deque<int> q;
	q.push_front(1);
	int k;
	cin >> k;
	for (int i = 2;i <= n;i++) {
		while (!q.empty() && q.back() + k < i) q.pop_back();
		if (d[q.back()] <= d[i]) dp[i] = min(dp[i],dp[q.back()] + 1);
		else dp[i] = min(dp[i],dp[q.back()]);
		while (!q.empty() && (dp[i] < dp[q.front()] || dp[i] == dp[q.front()] && d[i] >= d[q.front()])) q.pop_front();
		q.push_front(i);
	}
	cout << dp[n] << endl;
}

int main() {
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> d[i];
	int q;
	cin >> q;
	while (q--) solve();
	return 0;
}