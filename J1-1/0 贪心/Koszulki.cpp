#include<iostream>
using namespace std;

int a[2005],cnt[125];

int main()
{
	int n,k;
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		cnt[a[i]]++;
	}
	int tmp = 0;
	for (int i = 120;i >= 1;i--)
	{
		tmp += cnt[i];
		if (tmp >= k)
		{
			cout << tmp << endl;
			return 0;
		}
	}
	return 0;
}