#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int num[11] = {6,2,5,5,4,5,6,3,7,6},dp[15][10005],a[15];

int main(){
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= m;i++) cin >> a[i];
	sort(a + 1,a + m + 1,greater<int>());
	memset(dp,-0x3f,sizeof dp);
	dp[0][0] = 0;
	for (int i = 1;i <= m;i++)
		for (int j = 0;j <= n;j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= num[a[i]])
			{
				dp[i][j] = max(dp[i][j],dp[i][j - num[a[i]]] + 1);
			}
		}
	int len = dp[m][n];
	for (int k = 1;k <= len;k++)
	{
		for  (int i = 1;i <= m;i++)
		{
			if (num[a[i]] <= n && dp[m][n - num[a[i]]] + 1 == dp[m][n])
			{
				n -= num[a[i]];
				cout << a[i];
				break;
			}
		}
	}
	return 0;
}
