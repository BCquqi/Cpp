#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
int v[20 * N],w[20 * N],dp[2][40005];

int main() {
	int n,W;
	cin >> n >> W;
	int cur = 0;
	for (int i = 1;i <= n;i++)
	{
		int x,y,z;
		cin >> x >> y >> z;
		int tmp = 1;
		while (z >= tmp)
		{
			v[++cur] = tmp * x;
			w[cur] = tmp * y;
			z -= tmp;
			tmp *= 2;
		}
		if (z > 0)
		{
			v[++cur] = z * x;
			w[cur] = z * y;
		}
	}
	for (int i = 1;i <= cur;i++)
		for (int j = 0;j <= W;j++)
		{
			dp[i & 1][j] = dp[i - 1 & 1][j];
			if (j >= w[i]) dp[i & 1][j] = max(dp[i - 1 & 1][j],dp[i - 1 & 1][j - w[i]] + v[i]);
		}
	cout << dp[cur & 1][W] << endl;
	return 0;
}
