#include<iostream>
using namespace std;

const int N = 2005,mod = 1e9 + 7;
char c[N];
long long comb[N][N],box['z' + 5];

int main()
{
	int n,cnt = 0;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> c[i];
		box[c[i]]++;
	}
	for (int i = 0;i <= n;i++)
	{
		comb[i][0] = 1;
		for (int j = 1;j <= i;j++)
			comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
	}
	long long tot = 1,ans = 1; int l = n / 2;
	for (int i = 1;i <= n;i++) tot *= i,tot %= mod;
	for (int i = 'a';i <= 'z';i++)
	{
		cnt += box[i] % 2,ans *= comb[l][box[i] / 2],ans %= mod,l -= box[i] / 2;
		for (int j = 1;j <= box[i];j++) ans *= j,ans %= mod;
	}
	if (cnt > 1) ans = 0;
	cout << (tot - ans + mod) % mod << endl;
	return 0;
}