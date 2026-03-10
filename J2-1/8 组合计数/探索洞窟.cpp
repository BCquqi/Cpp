#include<iostream>
using namespace std;

const int N = 2005;
int c[N][N];

int main()
{
	int n,k,p;
	long long ans = 1;
	cin >> n >> k >> p;
	for (int i = 0;i <= n;i++)
	{
		c[i][0] = 1;
		for (int j = 1;j <= i;j++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % p;
	}
	for (int i = 1;i <= k;i++)
	{
		int x;
		cin >> x;
		ans *= c[n][x],ans %= p,n -= x;
	}
	cout << ans % p << endl;
	return 0;
}