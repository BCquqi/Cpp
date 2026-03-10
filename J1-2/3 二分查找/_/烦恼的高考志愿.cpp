#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int a[100005];

int main()
{
	int m,n;
	cin >> m >> n;
	for (int i = 1;i <= m;i++)
		cin >> a[i];
	sort(a + 1,a + m + 1);
	long long ans = 0,score;
	for (int i = 1;i <= n;i++)
	{
		cin >> score;
		int pos = lower_bound(a + 1,a + m + 1,score) - a;
		if (pos == m + 1) ans += score - a[m];
		else if (pos == 1) ans += a[1] - score;
		else ans += min(abs(a[pos] - score),abs(score - a[pos - 1]));
	}
	cout << ans << endl;
	return 0;
}
