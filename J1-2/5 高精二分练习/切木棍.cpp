#include<iostream>
#include<algorithm>
using namespace std;

int a[200005],n,k;

bool check(int mid)
{
	int cnt = 0;
	for (int i = 1;i <= n;i++) cnt += a[i] / mid;
	return cnt <= k;
}

int main()
{
	cin >> n >> k;
	for (int i = 1;i <= n;i++) cin >> a[i];
	int L = 1,R = 1e9,ans = -1;
	while (L <= R)
	{
		int mid = L + R >> 1;
		if (check(mid))
		{
			R = mid - 1;
			ans = mid;
		}
		else L = mid + 1;
	}
	cout << ans << endl;
	return 0;
}
