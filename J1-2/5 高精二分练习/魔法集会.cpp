#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

long long c[100005],n,k;
bool flag[100005];

bool check(long long mid)
{
	long long cnt = 0;
	int tmp = 0;
	for (int i = 1;i <= n;i++)
	{
		cnt += (c[i] + tmp) / mid;
		if (c[i] + tmp > mid)
			tmp = (c[i] + tmp) % mid;
		else tmp = c[i];
	}
	return cnt >= k;
}

void solve()
{
	memset(c,0,sizeof c);
	cin >> n >> k;
	for (int i = 1;i <= n;i++) cin >> c[i];
	long long L = 1,R = 1e18,ans = 0;
	while (L <= R)
	{
		long long mid = L + R >> 1;
		if (check(mid))
		{
			L = mid + 1;
			ans = mid;
		}
		else R = mid - 1;
	}
	cout << ans * k << endl;
	return ;
}

int main(){
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}
