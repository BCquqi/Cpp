#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(Node x,Node y)
{
	return x.e < y.e;
}

int main()
{
	sort(a + 1,a + n + 1,cmp);
	int ans = 1,pik = 1;
	for (int i = 2;i <= n;i++)
	{
		if (a[i].b > a[pik].e)
		{
			ans++;
			pik = i;
		}
	}
	return 0; 
}
