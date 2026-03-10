#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int n,m,a[100005],maxn = 0;

bool check(int mid)
{
	if (maxn > mid) return false;
	int cnt = 1,sum = 0;
	for (int i = 1;i <= n;i++)
	{
		if (sum + a[i] <= mid) sum += a[i];
		else cnt++,sum = a[i];
	}
	return cnt <= m;
}

int main(){
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		maxn = max(maxn,a[i]);
	}
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
