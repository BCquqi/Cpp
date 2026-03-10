#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int x[100005],n,m;

bool check(int mid)
{
	int pos = 1,cnt = 1;
	for (int i = 2;i <= n;i++)
	{
		if (x[i] - x[pos] >= mid)
		{
			cnt++;
			pos = i;
		}
	}
	return cnt >= m;
}

int main(){
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> x[i];
	sort(x + 1,x + n + 1);
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
