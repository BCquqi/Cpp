#include<iostream>
#include<algorithm>
using namespace std;

int b[300005],n;

bool check(int i)
{
	int cur = n - i;
	for (int j = i + 1;j <= n;j++)
	{
		if (b[i] + n < b[j] + cur) return false;
		cur--;
	}
	return true;
}

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> b[i];
	sort(b + 1,b + n + 1);
	int ans = 0;
	for (int i = 1;i <= n;i++)
	{
		if (check(i)) ans++;
	}
	cout << ans << endl;
	return 0;
}