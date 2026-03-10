#include<iostream>
#include<algorithm>
using namespace std;

const int N = 505;
struct Node {
	int w,v;
} a[N];
int dp[N][20005];

bool cmp(Node x,Node y)
{
	return x.w < y.w;
}

int main()
{
	int n,m,l,s;
	cin >> n >> m >> l >> s;
	for (int i = 1;i <= n;i++) cin >> a[i].w;
	for (int i = 1;i <= n;i++) cin >> a[i].v;
	sort(a + 1,a + n + 1,cmp);
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= s + m;j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= a[i].w) dp[i][j] = max(dp[i][j],dp[i - 1][j - a[i].w] + a[i].v);
		}
	int ans = 0;
	for (int i = 0;i <= m;i++)
	{
		int c = l + m - i,t = n;
		for (int j = 1;j <= n;j++)
			if (a[j].w > c)
			{
				t = j - 1;
				break;
			}
		ans = max(ans,dp[t][s + i]);
	}
	cout << ans << endl; 
	return 0;
}
