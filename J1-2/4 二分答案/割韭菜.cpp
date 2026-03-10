#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int a[1000005],n,m;

bool check(int mid)
{
	long long cnt = 0;
	for (int i = 1;i <= n;i++)
		if (a[i] >= mid)
			cnt += a[i] - mid;
	return cnt >= m;
}

int main(){
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	int L = 1,R = 2e9,ans = 0;
	while (L <= R)
	{
		int mid = L + R >> 1;
		if (check(mid))
		{
			L = mid + 1;
			ans = mid;
		}
		else R = mid - 1;
	}
	cout << ans << endl;
	return 0;
}
