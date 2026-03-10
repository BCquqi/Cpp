#include<iostream>
#include<algorithm>
using namespace std;

long long n,z[105],a[105],b[105];
long long p;

bool check(long long mid)
{
	long long ret = 0;
	for (int i = 1;i <= n;i++)
	{
		if (mid <= z[i]) ret += a[i] * mid;
		else ret += a[i] * z[i] + b[i] * (mid - z[i]);
	}
	return ret >= p;
}

int main()
{
	cin >> n >> p;
	for (int i = 1;i <= n;i++) cin >> z[i] >> a[i] >> b[i];
	long long L = 1,R = p;
	while (L <= R)
	{
		long long mid = L + R >> 1;
		if (check(mid)) R = mid - 1;
		else L = mid + 1;
	}
	cout << L << endl;
	return 0;
}
