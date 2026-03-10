#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int dp[2005][2005];

int main(){
	string A,B;
	cin >> A >> B;
	int n = A.size(),m = B.size();
	A = '?' + A;
	B = '?' + B;
	memset(dp,0x3f,sizeof dp);
	dp[0][0] = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
		{
			dp[i][j] = min(min(dp[i - 1][j] + 1,dp[i][j - 1] + 1),dp[i - 1][j - 1] + 1);
			if (A[i] == B[j]) dp[i][j] = min(dp[i][j],dp[i - 1][j - 1]);
		}
	cout << dp[n][m] << endl;
	return 0;
}
