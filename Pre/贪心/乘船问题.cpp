#include<iostream>
#include<algorithm>
using namespace std;

int a[200005];

int main()
{
	int n,k;
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	int l = 1,r = n;
	int ans = 0;
	while (l <= r)
	{
		if (a[l] + a[r] <= k)
		{
			l++; 
		}
		ans++;
		r--;
	}
	cout << ans << endl;
	return 0;
}
