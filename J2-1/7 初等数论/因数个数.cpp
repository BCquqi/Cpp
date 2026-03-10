#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1e3 + 5,M = 1e4 + 5,mod = 1e9 + 7;
int a[N],b[M];

void solve()
{
	memset(a,0,sizeof a); memset(b,0,sizeof b);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		for (int j = 2;j * j <= a[i];j++)
			while (a[i] % j == 0) b[j]++,a[i] /= j;
		if (a[i] > 1) b[a[i]]++;
	}
	bool flag = true; long long ans = 1;
	for (int i = 1;i <= 1e4;i++)
	{
		if (b[i] % 2 != 0) {flag = false; break;}
		ans *= b[i] / 2 + 1,ans %= mod;
	}
	if (!flag) {cout << -1 << endl; return ;}
	else cout << ans % mod << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}