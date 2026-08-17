#include<iostream>
#include<queue>
#define int long long
using namespace std;

const int N = 1e7 + 5;
int a[N],Seed,dp[N];
// dp[i] 表示处理完第 i 个人所需最小精力

deque<int> q;

inline int rnd () {
	static const int MOD = 1e9;
	return Seed = ( 1LL * Seed * 0x66CCFF % MOD + 20120712 ) % MOD;
}

signed main() {
	int n,k,d,x,tp;
	cin >> n >> k >> d >> x >> tp; 
	if (tp == 0)
		for (int i = 1;i <= n;i++)
			cin >> a[i];
	else  {
		cin >> Seed;
		for (int i = 1;i <= n;i++)
			a[i] = rnd();
	}
	dp[1] = a[1];
	q.push_back(1); 
	for (int i = 2;i <= n;i++) {
		while (!q.empty() && q.front() < i - x) q.pop_front();
		dp[i] = a[i] + k + dp[q.front()] + 1ll * d * (i - q.front() - 1);
		while (!q.empty() && dp[q.back()] - 1ll * q.back() * d >= dp[i] - 1ll * i * d) q.pop_back();
		q.push_back(i); 
	} 
	cout << dp[n] << endl;
	return 0;
} 
