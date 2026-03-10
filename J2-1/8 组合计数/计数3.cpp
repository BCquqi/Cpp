#include<iostream>
using namespace std;

const int mod = 1e9 + 7;

int main()
{
	int n;
	cin >> n;
	long long ans = 1;
	for (int i = 1;i <= n - 1;i++) ans *= 4, ans %= mod;
	cout << ans * n % mod << endl;
	return 0;
}