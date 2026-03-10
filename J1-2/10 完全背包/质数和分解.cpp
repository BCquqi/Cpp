#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

long long dp[2][1005];

bool isPrime(int x)
{
	if (x == 0 || x == 1) return false;
	for (int i = 2;i * i <= x;i++)
		if (x % i == 0) return false;
	return true;
}

int main(){
	int n;
	cin >> n;
	dp[0][0] = 1;
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= n;j++)
		{
			dp[i & 1][j] = dp[i - 1 & 1][j];
			if (isPrime(i) && j >= i) dp[i & 1][j] += dp[i & 1][j - i];
		}
	cout << dp[n & 1][n] << endl;
	return 0;
}
