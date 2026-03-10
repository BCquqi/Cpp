#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N = 100005;
int h[N],w[N],n,k;

bool check(int mid)
{
	long long cnt = 0;
	for (int i = 1;i <= n;i++) cnt += (h[i] / mid) * (w[i] / mid);
	return cnt >= k;
}

int main()
{
	cin >> n >> k;
	for (int i = 1;i <= n;i++) cin >> h[i] >> w[i];
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
