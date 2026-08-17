#include<iostream>
#include<cstring>
#define int long long
using namespace std;

const int N = 3e5 + 5;
int t[N],c[N],st[N],sc[N],dp[N],stk[N],top = 1;

signed main() {
	int n,s,top = 0;
	cin >> n >> s;
	for (int i = 1;i <= n;i++) {
		cin >> t[i] >> c[i];
		st[i] = st[i - 1] + t[i], sc[i] = sc[i - 1] + c[i];
	}
	memset(dp,0x3f,sizeof dp);
	st[0] = dp[0] = 0;
	int l,r,res;
	for (int i = 1;i <= n;i++) {
		l = 1,r = top,res = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (dp[stk[mid]] - dp[stk[mid - 1]] <= (st[i] + s) * (sc[stk[mid]] - sc[stk[mid - 1]])) l = mid + 1, res = mid;
			else r = mid - 1;
		}
		res = stk[res];
		dp[i] = dp[res] + s * (sc[n] - sc[res]) + st[i] * (sc[i] - sc[res]);
		while (top && (dp[stk[top]] - dp[stk[top - 1]]) * (sc[i] - sc[stk[top]]) >= (dp[i] - dp[stk[top]]) * (sc[stk[top]] - sc[stk[top - 1]])) --top;
		stk[++top] = i;
	}
	cout << dp[n] << endl;
	return 0;
} 
