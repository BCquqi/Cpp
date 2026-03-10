#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int d[15 * 20],dp[2][100005];

int main(){
	int M,N;
	cin >> M >> N;
	int cur = 0;
	for (int i = 1;i <= N;i++)
	{
		int x,z;
		cin >> x >> z;
		int tmp = 1;
		while (z >= tmp)
		{
			d[++cur] = tmp * x;
			z -= tmp;
			tmp *= 2;
		}
		if (z > 0) d[++cur] = z * x;
	}
	for (int i = 1;i <= cur;i++)
		for (int j = 1;j <= M;j++)
		{
			dp[i & 1][j] = dp[i - 1 & 1][j];
			if (j >= d[i]) dp[i & 1][j] = max(dp[i & 1][j],dp[i - 1 & 1][j - d[i]] + d[i]);
		}
	cout << dp[cur & 1][M] << endl;
	return 0;
}
