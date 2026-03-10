#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int l[10000005],n,k;

bool check(int mid)
{
	long long cnt = 0;
	for (int i = 1;i <= n;i++) cnt += l[i] / mid;
	return cnt >= k;
}

int main(){
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
	{
		double x;
		cin >> x;
		l[i] = int(x * 100);
	}
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
	printf("%.2lf\n",ans * 1.00 / 100);
	return 0;
}
