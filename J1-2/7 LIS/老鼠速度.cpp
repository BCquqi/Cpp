// 正常LIS 100pts
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

struct Node {
	int w,v;
} s[1005];

int dp[1005];

bool cmp(Node x,Node y)
{
	if (x.v != y.v) return x.v > y.v;
	else return x.w > y.w;
}

int main(){
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> s[i].w >> s[i].v;
	sort(s + 1,s + n + 1,cmp);
	for (int i = 1;i <= n;i++)
		for (int j = 0;j < i;j++)
			if (s[j].w < s[i].w)
				dp[i] = max(dp[i],dp[j] + 1);
	int ans = 0;
	for (int i = 1;i <= n;i++) ans = max(ans,dp[i]);
	cout << ans << endl;
	return 0;
}

// 二分LIS 100pts
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

struct Node {
	int w,v;
} s[1005];

int dp[1005];

bool cmp(Node x,Node y)
{
	if (x.v != y.v) return x.v > y.v;
	else return x.w > y.w;
}

int main(){
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> s[i].w >> s[i].v;
	sort(s + 1,s + n + 1,cmp);
	int ans = 0;
	for (int i = 1;i <= n;i++)
	{
		int pos = lower_bound(dp + 1,dp + ans + 1,s[i].w) - dp;
		dp[pos] = s[i].w;
		ans = max(ans,pos);
	}
	cout << ans << endl;
	return 0;
}
