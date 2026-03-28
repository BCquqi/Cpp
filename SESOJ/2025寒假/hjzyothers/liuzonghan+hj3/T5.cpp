#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
unsigned long long n;
bool check(unsigned long long x)
{
	return (x*(x+1)>>1)<=n+1;
}
unsigned long long search(unsigned long long l,unsigned long long r)
{
	unsigned long long res=0;
	while(l<=r)
	{
		unsigned long long mid=(l+r)>>1;
		if(check(mid))
		{
			l=mid+1;
			res=n-mid+1;
		}
		else	r=mid-1;
	}
	return res;
}
int main()
{
	scanf("%llu",&n);
	printf("%llu\n",search(1,2e9));
	return 0;
}

