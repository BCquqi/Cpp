#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 45,M = 1605;
int l[N];
bool dp[2][M][M];

double helen(int a,int b,int c)
{
	double p = (a + b + c) / 2.0;
	double x = p * (p - a) * (p - b) * (p - c);
	if (x < 0) return 0;
	else return sqrt(x);
}

int main() {
	int n,sum = 0,ans = 0;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> l[i];
		sum += l[i];
	}
	dp[0][0][0] = true;
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= sum / 2;j++)
			for (int k = 0;k <= sum / 2;k++)
			{
				int l1 = j,l2 = k,l3 = sum - j - k;
				if (j >= l[i]) dp[i & 1][j][k] |= dp[i - 1 & 1][j - l[i]][k];
				if (k >= l[i]) dp[i & 1][j][k] |= dp[i - 1 & 1][j][k - l[i]];
				dp[i & 1][j][k] |= dp[i - 1 & 1][j][k];
			}
	for (int j = 0;j <= sum;j++)
		for (int k = 0;k <= sum;k++)
			if (dp[n & 1][j][k]) ans = max(ans,(int) floor(helen(sum - j - k,j,k) * 100));
	cout << (ans == 0 ? -1 : ans) << endl;
	return 0;
}
