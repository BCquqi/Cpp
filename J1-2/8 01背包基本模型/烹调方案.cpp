#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int dp[2][100005];

struct Node {
	int a,b,c;
} s[55];

bool cmp(Node x,Node y)
{
	return x.c * y.b < y.c * x.b;
}

int main() {
	int t,n;
	cin >> t >> n;
	for (int i = 1;i <= n;i++) cin >> s[i].a;
	for (int i = 1;i <= n;i++) cin >> s[i].b;
	for (int i = 1;i <= n;i++) cin >> s[i].c;
	sort(s + 1,s + n + 1,cmp);
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= t;j++)
		{
			dp[i & 1][j] = dp[i - 1 & 1][j];
			if (j >= s[i].c)
			{
				int tmp = dp[i - 1 & 1][j - s[i].c] + s[i].a - j * s[i].b;
				dp[i & 1][j] = max(dp[i & 1][j],tmp);
			}
		}
	int ans = 0;
	for (int j = 1;j <= t;j++) ans = max(dp[n & 1][j],ans);
	cout << ans << endl;
	return 0;
}
