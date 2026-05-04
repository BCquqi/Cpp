#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int N = 1e6 + 5;
int a[N];
long long dp[N];

int main() {
	int n,m,k,d;
	cin >> n >> m >> k >> d;
	for (int i = 1;i <= n;i++) cin >> a[i];
	deque<int> q;
	dp[1] = a[1];
	q.push_front(1);
	for (int i = 2;i <= n;i++) {
		while (!q.empty() && i - q.back() - 1 > m) q.pop_back();
		dp[i] = dp[q.back()] - 1ll * d * q.back() + k + 1ll * d * i - d + a[i];
		while (!q.empty() && dp[i] - 1ll * d * i < dp[q.front()] - 1ll * d * q.front()) q.pop_front();
		q.push_front(i);
	}
	cout << dp[n] << endl;
	return 0;
}