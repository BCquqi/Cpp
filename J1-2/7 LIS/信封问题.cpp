#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

struct Node {
	int w,h;
} s[200005];

int dp[200005];

bool cmp(Node x,Node y)
{
	if (x.h != y.h) return x.h < y.h;
	else return x.w > y.w;
}

int main(){
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> s[i].w;
	for (int i = 1;i <= n;i++) cin >> s[i].h;
	sort(s + 1,s + n + 1,cmp);
	int cnt = 0;
	for (int i = 1;i <= n;i++)
	{
		int pos = lower_bound(dp + 1,dp + cnt + 1,s[i].w) - dp;
		dp[pos] = s[i].w;
		cnt = max(cnt,pos);
	}
	cout << cnt << endl;
	return 0;
}
