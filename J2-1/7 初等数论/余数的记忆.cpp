#include<iostream>
using namespace std;

int main()
{
	int n,k;
	long long ans = 0;
	cin >> n >> k;
	if (k == 0) {cout << 1ll * n * n << endl; return 0;}
	for (int b = k + 1;b <= n;b++)
		ans += 1ll * (b - k) * (n / b) + 1ll * max(0,n % b - k + 1);
	cout << ans << endl;
	return 0;
}