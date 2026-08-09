#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1005;
int a[N],len[N],lcur = 0,in[N];
bool flag[N],dp[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("queue.in","r",stdin);
	freopen("queue.out","w",stdout);
	int n,x,m = 0,pos = 0;
	cin >> n >> x;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		flag[a[i]] = true;
	}
	for (int i = 1;i <= n;i++) {
		if (flag[i]) continue;
		int cur = i,cnt = 0;
		bool tmpflag = false;
		while (cur) {
			if (cur == x) tmpflag = true,pos = cnt;
			cnt++;
			cur = a[cur];
		}
		if (tmpflag) m = cnt - pos;
		else len[++lcur] = cnt;
	}
	dp[0] = true;
	for (int i = 1;i <= lcur;i++)
		for (int j = n;j >= len[i];j--)
			dp[j] |= dp[j - len[i]];
	for (int j = 0;j <= n;j++)
		if (dp[j]) cout << j + m << '\n';
	return 0;
}
