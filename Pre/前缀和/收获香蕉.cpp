#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int a[5005],sum[5005],ans = 0;

int main(){
	int n,k;
	cin >> n >> k;
	sum[0] = 0;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	for (int l = 1;l <= n;l++)
	{
		for (int r = l;r <= n;r++)
		{
			if (sum[r] - sum[l - 1] >= k) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
