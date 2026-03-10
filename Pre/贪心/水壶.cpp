#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[1000005],s[1000005];

int main() {
	int n,k;
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		s[i] += s[i - 1] + a[i];
	}
	int ans = 0;
	for (int i = k + 1;i <= n;i++)
	{
		ans = max(ans,s[i] - s[i - k - 1]);
	}
	cout << ans << endl;
    return 0;
}
