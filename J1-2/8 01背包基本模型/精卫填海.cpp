#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int k[10005],m[10005],dp[2][10005];

int main(){
	int v,n,c;
	cin >> v >> n >> c;
	for (int i = 1;i <= n;i++) cin >> k[i] >> m[i];
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= c;j++)
		{
			dp[i & 1][j] = dp[i - 1 & 1][j];
			if (j >= m[i])
				dp[i & 1][j] = max(dp[i & 1][j],dp[i - 1 & 1][j - m[i]] + k[i]);
		}
	if (dp[n & 1][c] < v) cout << "Impossible" << endl;
	else for (int j = 1;j <= c;j++)
		if (dp[n & 1][j] >= v) 
		{
			cout << c - j << endl;
			break;
		}
	return 0;
}
