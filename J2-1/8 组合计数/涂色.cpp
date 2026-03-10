#include<iostream>
using namespace std;

const int mod = 1e9 + 7;

int main()
{
	int n,k;
	cin >> n >> k;
	int ans = k % mod;
	for (int i = 2;i <= n;i++) ans *= (k - 1),ans %= mod;
	cout << ans << endl;
	return 0;
}