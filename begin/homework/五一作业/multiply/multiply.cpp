#include<iostream>
#include<algorithm>
using namespace std;
#define int long long

int n, x;
int a[105];

signed main()
{
	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			int mul = 1;
			for (int k = i; k <= j; k++)
			{
				if (mul > 10000) 
				{
					mul = 1e9;
					break;
				}
				mul *= a[k];
			}
			if (mul == x) 
			{
				cout << i << " " << j;
				return 0;
			 } 
		}
	}
	cout << -1;
	return 0;
}