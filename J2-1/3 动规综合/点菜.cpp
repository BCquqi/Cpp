#include<iostream>
#include<algorithm>
using namespace std;

const int N = 3005;
int dp[N][2 * N];

struct Node {
	int a,b;
} s[N];

bool cmp(Node x,Node y)
{
	return x.a < y.a;
}

int main()
{
	int n,t;
	cin >> n >> t;
	for (int i = 1;i <= n;i++) cin >> s[i].a >> s[i].b;
	sort(s + 1,s + n + 1,cmp);
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= 6000;j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= s[i].a && j - s[i].a < t) dp[i][j] = max(dp[i][j],dp[i - 1][j - s[i].a] + s[i].b);
		}
	int ans = 0;
	for (int i = 0;i <= 6000;i++)
		ans = max(ans,dp[n][i]);
	cout << ans << endl;
	return 0;
}
