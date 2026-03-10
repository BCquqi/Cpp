#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int mod = 1e9 + 7;
long long dp[5][10005];
//dp[1]表示包含偶数个1的n位数的个数
//dp[2]表示包含奇数个1的n位数的个数

int main(){
	int n;
	cin >> n;
	if (n == 1) {cout << 9 << endl;return 0;}
	dp[1][1] = 8;
	dp[2][1] = 1;
	for (int i = 2;i <= n;i++)
	{
		dp[1][i] = (dp[2][i - 1] + dp[1][i - 1] * 9) % mod;
		dp[2][i] = (dp[1][i - 1] + dp[2][i - 1] * 9) % mod;
	}
	cout << dp[1][n] % mod << endl;
	return 0;
}
