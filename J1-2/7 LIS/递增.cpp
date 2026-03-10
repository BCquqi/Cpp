// 正常LIS 80pts
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[100005],dp[100005];

int main(){
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++)
		for (int j = 0;j < i;j++)
			if (a[j] < a[i])
				dp[i] = max(dp[i],dp[j] + 1);
	int ans = 0;
	for (int i = 1;i <= n;i++) ans = max(ans,dp[i]);
	cout << n - ans << endl;
	return 0;
}

// 二分LIS 100pts
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[100005],dp[100005];

int main(){
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	int cnt = 0;
	for (int i = 1;i <= n;i++)
	{
		int pos = lower_bound(dp + 1,dp + cnt + 1,a[i]) - dp;
		dp[pos] = a[i];
		cnt = max(cnt,pos);
	}
	cout << n - cnt << endl;
	return 0;
}
