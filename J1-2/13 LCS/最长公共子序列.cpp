#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int dp[1005][1005];

int main(){
	int n,m;
	string A,B;
	cin >> n >> m >> A >> B;
	A = '?' + A;
	B = '?' + B;
	dp[0][0] = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
		{
			dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
			if (A[i] == B[j]) dp[i][j] = max(dp[i][j],dp[i - 1][j - 1] + 1);
		}
	cout << dp[n][m] << endl;
	return 0;
}
