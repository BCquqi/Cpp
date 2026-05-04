#include<iostream>
#include<deque>
#include<cstring>
using namespace std;

const int N = 5e5 + 5;
int x[N],s[N],n,d,k;
long long dp[N];

bool check(int g) {
	memset(dp,-0x3f,sizeof dp);
	dp[0] = 0;
	int dis1 = max(1,d - g),dis2 = d + g,cur = 0;
	deque<int> q;
	for (int i = 1;i <= n;i++) {
		while (x[i] - x[cur] >= dis1 && cur < i) {
			while (!q.empty() && dp[cur] >= dp[q.front()]) q.pop_front();
			q.push_front(cur);
			cur++;
		}
		while (!q.empty() && x[i] - x[q.back()] > dis2) q.pop_back();
		if (q.empty()) continue;
		dp[i] = max(dp[i],dp[q.back()] + s[i]);
		if (dp[i] >= k) return true;
	}
	return false;
}

int main() {
	cin >> n >> d >> k;
	for (int i = 1;i <= n;i++) cin >> x[i] >> s[i];
	int L = 0,R = x[n],ans = 0;
	while (L <= R) {
		int mid = L + R >> 1;
		if (check(mid)) R = mid - 1,ans = mid;
		else L = mid + 1;
	}
	cout << (ans == 0 ? -1 : ans) << endl;
	return 0;
}