#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int l[100005],n,k;

bool check(int mid)
{
	long long cnt = 0;
	for (int i = 1;i <= n;i++) cnt += l[i] / mid;
	return cnt >= k;
}

int main(){
	cin >> n >> k;
	for (int i = 1;i <= n;i++) cin >> l[i];
	int L = 1,R = 1e8,ans = -1;
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
