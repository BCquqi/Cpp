#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;

const int N = 30;
int a[N];
LL dp[N][10005];

int main(){
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	dp[0][0] = 1;
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= m;j++)
		{
			dp[i][j] = dp[i - 1][j];
			for (int k = 1;j >= k * a[i];k++)
				dp[i][j] += dp[i - 1][j - k * a[i]];
		}
	cout << dp[n][m] << endl;
	return 0;
}