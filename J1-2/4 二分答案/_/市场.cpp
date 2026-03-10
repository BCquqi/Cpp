// 本题为格式化输入输出题
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int n,m;
long long a[1000005],b[1000005];

bool check(long long mid)
{
	int posa = upper_bound(a + 1,a + n + 1,mid) - a - 1;
	int posb = m - (lower_bound(b + 1,b + m + 1,mid) - b) + 1;
	return posa >= posb;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) scanf("%lld",&a[i]);
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= m;i++) scanf("%lld",&b[i]);
	sort(b + 1,b + m + 1);
	long long L = 1,R = 1e18;
	while (L <= R)
	{
		long long mid = L + R >> 1;
		if (check(mid)) R = mid - 1;
		else L = mid + 1;
	}
	printf("%lld\n",L);
	return 0;
}
