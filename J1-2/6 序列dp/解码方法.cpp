#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int dp[55];

int main(){
	string s;
	cin >> s;
	int n = s.size();
	s = '?' + s;
	dp[0] = 1,dp[1] = 1;
	for (int i = 2;i <= n;i++)
	{
		int num = (s[i - 1] - '0') * 10 + (s[i] - '0');
		dp[i] += dp[i - 1];
		if (num >= 10 && num <= 25) dp[i] += dp[i - 2];
	}
	cout << dp[n] << endl;
	return 0;
}
