#include<iostream>
using namespace std;

const int N = 5005,mod = 1e9 + 7;
int c[N][N];

int main()
{
	int n,m,k;
	cin >> n >> m >> k;
	for (int i = 0;i <= n;i++)
	{
		c[i][0] = 1;
		for (int j = 1;j <= i;j++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
	}
	if (n - (m - 1) * k >= m) cout << c[n - (m - 1) * k][m] << endl;
	else cout << 0 << endl;
	return 0;
}