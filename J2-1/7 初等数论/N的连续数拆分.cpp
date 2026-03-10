#include<iostream>
using namespace std;

int main()
{
	long long n,ans = 0;
	cin >> n;
	for (long long i = 1;1ll * i * i <= 2 * n;i++)
		if (2 * n % i == 0 && (i % 2) != ((2 * n / i) % 2)) ans++;
	cout << ans << endl;
	return 0;
}