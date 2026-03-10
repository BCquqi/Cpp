#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

long long a[100005];

int main()
{
	int n,Q;
	cin >> n >> Q;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= Q;i++)
	{
		long long k;
		cin >> k;
		int pos = upper_bound(a + 1,a + n + 1,k - 1) - a;
		for (int i = 1;i <= 20;i++)
			pos = upper_bound(a + 1,a + n + 1,k + pos - 1) - a;
		cout << k + pos - 1 << endl;
	}
	return 0;
}
