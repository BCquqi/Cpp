#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int a[1005],dp[1005];

int main(){
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	memset(dp,-0x3f,sizeof dp);
	dp[0] = 0;
	for (int i = 1;i <= n;i++)
	{
		int k = 0;
		for (int j = i;j >= 1;j--)
		{
			k += a[j];
			if (k >= 0) dp[i] = max(dp[i],dp[j - 1] + 1);
		}
	}
	if (dp[n] <= 0) cout << "Impossible" << endl;
	else cout << dp[n] << endl;
	return 0;
}
