#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;

long long a[200005];

map<long long,int> mp1,mp2;

int main() {
	int n,q;
	cin >> n >> q;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		mp2[a[i]]++;
	}
	mp1[a[1]]++;
	mp2[a[1]]--;
	mp2[a[2]]--;
	long long ans = 0;
	for (int j = 2;j <= n - 1;j++)
	{
		if (a[j] % q == 0)
			ans += 1ll * mp1[a[j] / q] * mp2[a[j] * q];
		mp1[a[j]]++;
		mp2[a[j + 1]]--;
	}
	cout << ans << endl;
    return 0;
}
