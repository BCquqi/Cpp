#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 505,M = 10005;
struct Node {int x,f,c;} s[N];
long long dp[N][M];

long long f(int i,int t) {return dp[i - 1][t] + 1ll * (s[i].x - s[i - 1].x) * t * t - 1ll * t * s[i].c;}

int main() {
	int K,e,n;
	cin >> K >> e >> n;
	for (int i = 1;i <= n;i++) cin >> s[i].x >> s[i].f >> s[i].c;
	sort(s + 1,s + n + 1,[](Node x,Node y) {return x.x < y.x;});
	memset(dp,0x3f,sizeof dp);
	dp[0][0] = 0;
	deque<int> q;
	for (int i = 1;i <= n;i++) {
		q.clear();
		for (int k = 0;k <= K;k++) {
			while (!q.empty() && q.back() < max(0,k - s[i].f)) q.pop_back();
			while (!q.empty() && f(i,k) <= f(i,q.front())) q.pop_front();
			q.push_front(k);
			int t = q.back();
			dp[i][k] = dp[i - 1][t] + 1ll * (s[i].x - s[i - 1].x) * t * t - 1ll * t * s[i].c + 1ll * k * s[i].c;
		}
	}
	cout << dp[n][K] + 1ll * (e - s[n].x) * K * K << endl;
	return 0;
}