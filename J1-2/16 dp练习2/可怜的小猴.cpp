#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int s[2505],t[2505],dp[];

/*
要前缀和
dp
区间合并?
*/

int main()
{
	int n,T;
	for (int i = 1;i <= n;i++)
	{
		cin >> t[i];
		s[i] = s[i - 1] + t[i];
	}
	memset(dp,0x3f,sizeof dp);
	for (int len = 2;len <= n;len++)
		for (int i = 1;i <= n;i++)
		{
			int j = i + len - 1;
			for (int k = i;k < j;k++)
			{
				dp[i][j] = min(dp[i][j],dp[i][k] + dp[k + 1][j])
			}
		}
	return 0;
}
