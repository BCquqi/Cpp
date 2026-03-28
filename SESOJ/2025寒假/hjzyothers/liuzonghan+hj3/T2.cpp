#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long mod = 1e9+7;
long long n,a[1<<18],q[1<<18];
long long ans = 1;
int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) 
	    cin >> a[i];
	sort(a+1,a+n+1);
	for (int i = 1; i <= n; i++) 
	    q[i] = a[i] - a[i - 1];
	for (int i = 1; i <= n; i++) 
	{
		ans *= (q[i] + 1ll);
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}
