#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int a[1005][1005],dp[1005][1005];

int main(){
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			cin >> a[i][j];
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]) + a[i][j];
	cout << dp[n][m] << endl;
	return 0;
}
