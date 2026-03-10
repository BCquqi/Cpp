#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int a[205],s[205],dp1[205][205],dp2[205][205];

int main(){
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = n + 1;i <= 2 * n;i++) a[i] = a[i - n];
	for (int i = 1;i <= 2 * n;i++) s[i] = s[i - 1] + a[i];
	memset(dp2,0x3f,sizeof dp2);
	for (int i = 1;i <= 2 * n;i++) dp2[i][i] = 0;
	for (int len = 2;len <= n;len++)
		for (int i = 1;i + len - 1 <= 2 * n;i++)
		{
			int j = i + len - 1;
			for (int k = i;k < j;k++)
			{
				dp1[i][j] = max(dp1[i][j],dp1[i][k] + dp1[k + 1][j] + s[j] - s[i - 1]);
				dp2[i][j] = min(dp2[i][j],dp2[i][k] + dp2[k + 1][j] + s[j] - s[i - 1]);
			}
		}
	int ans1 = 0,ans2 = 1e9;
	for (int i = 1;i <= n;i++) ans1 = max(ans1,dp1[i][i + n - 1]);
	for (int i = 1;i <= n;i++) ans2 = min(ans2,dp2[i][i + n - 1]);
	cout << ans2 << endl << ans1 << endl;
	return 0;
}
