#include<iostream>
using namespace std;

int a[3005];

int main()
{
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	int ans = 1e9;
	for (int i = 1;i <= n - m + 1;i++)
	{
		int sum = 0;
		for (int j = i + 1;j <= i + m;j++)
		{
			sum += a[j];
		}
		ans = min(ans,sum);
	}
	cout << ans << endl;
	return 0;
}