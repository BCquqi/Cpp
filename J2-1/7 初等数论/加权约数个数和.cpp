#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	long long ans = 0;
	for (int i = 1;i <= n;i++) ans += 1ll * (i + n / i * i) * (n / i) / 2;
	cout << ans << endl;
	return 0;
}