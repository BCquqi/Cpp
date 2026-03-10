#include<iostream>
using namespace std;

int a[500005];
bool flag[500005];

int main()
{
	int n,k;
	cin >> n >> k;
	long long cnt = 0,ans = 0;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (!flag[a[i]])
		{
			flag[a[i]] = true;
			ans += i - cnt - 1;
			cnt++;
		}
		if (cnt == k)
		{
			cout << ans << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}
