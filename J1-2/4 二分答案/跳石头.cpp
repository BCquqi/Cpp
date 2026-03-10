#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int l,n,m,d[50005];

bool check(int mid)
{
	int pos = 0,cnt = 0;
	for (int i = 1;i <= n + 1;i++)
	{
		if (d[i] - d[pos] < mid) cnt++;
		else pos = i;
	}
	return cnt <= m;
}

int main(){
	cin >> l >> n >> m;
	for (int i = 1;i <= n;i++) cin >> d[i];
	d[n + 1] = l;
	sort(d + 1,d + n + 1);
	int L = 1,R = 1e9,ans = -1;
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
