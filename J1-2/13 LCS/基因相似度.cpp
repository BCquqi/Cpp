#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int dp[5005][5005];
int score[5][5] = {
	{5,-1,-2,-1,-3},
	{-1,5,-3,-2,-4},
	{-2,-3,5,-2,-2},
	{-1,-2,-2,5,-1},
	{-3,-4,-2,-1,-1e9}
};

int f(char a,char b)
{
	int s,t;
	if (a == 'A') s = 0;
	else if (a == 'C') s = 1;
	else if (a == 'G') s = 2;
	else if (a == 'T') s = 3;
	else s = 4;
	if (b == 'A') t = 0;
	else if (b == 'C') t = 1;
	else if (b == 'G') t = 2;
	else if (b == 'T') t = 3;
	else t = 4;
	return score[s][t];
}

int main() {
	int l1,l2;
	string a,b;
	cin >> l1 >> a >> l2 >> b;
	a = '?' + a;
	b = '?' + b;
	memset(dp,-0x3f,sizeof dp);
	dp[0][0] = 0;
	for (int i = 1;i <= l1;i++) dp[i][0] = dp[i - 1][0] + f(a[i],'-');
	for (int j = 1;j <= l2;j++) dp[0][j] = dp[0][j - 1] + f(b[j],'-');
	for (int i = 1;i <= l1;i++)
		for (int j = 1;j <= l2;j++)
			dp[i][j] = max(dp[i - 1][j - 1] + f(a[i],b[j]),max(dp[i][j - 1] + f(b[j],'-'),dp[i - 1][j] + f(a[i],'-')));
	cout << dp[l1][l2] << endl;
	return 0;
}
