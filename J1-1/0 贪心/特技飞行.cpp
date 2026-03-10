#include<iostream>
#include<algorithm>
using namespace std;

int c[305];

int main()
{
	int n,k;
	cin >> n >> k;
	for (int i = 1;i <= k;i++)
	{
		cin >> c[i];
	}
	sort(c + 1,c + k + 1,greater<int>());
	int ans = 0;
	for (int l = 1,r = n;l < r;l++,r--) ans += c[l] * (r - l);
	cout << ans << endl;
	return 0;
}